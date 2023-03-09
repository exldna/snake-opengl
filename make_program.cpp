//
// Created by asuka on 09.03.2023.
//

# include <make_program.hpp>
# include <glad/glad.h>
# include <fstream>
# include <iostream>

std::string load_shader_source(const std::filesystem::path& name) {
    auto path = "./shaders" / name;
    auto file = std::ifstream(path);
    std::string line;
    std::string source;
    while (file.good()) {
        std::getline(file, line);
        source += line;
        source += '\n';
    }
    return source;
}

unsigned int make_shader(GLenum shader_type, const std::filesystem::path& shader_path) {
    auto shader_source = load_shader_source(shader_path);
    auto shader_source_data = shader_source.c_str();

    unsigned int shader = glCreateShader(shader_type);
    glShaderSource(shader, 1, &shader_source_data, nullptr);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char info_log[512];
        glGetShaderInfoLog(shader, 512, nullptr, info_log);
        std::cout << "failed to compile shader\n";
        std::cout << "\tfile: " << shader_path << '\n';
        std::cout << "\tlog: " << info_log << '\n';
        throw std::runtime_error("failed to compile shader");
    }

    return shader;
}

unsigned int snake::make_program(
        const std::filesystem::path& vertex_shader_path,
        const std::filesystem::path& fragment_shader_path) {

    auto vertex_shader = make_shader(GL_VERTEX_SHADER, vertex_shader_path);
    auto fragment_shader = make_shader(GL_FRAGMENT_SHADER, fragment_shader_path);

    auto program = glCreateProgram();

    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);

    glLinkProgram(program);

    int success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        char info_log[512];
        glGetProgramInfoLog(program, 512, nullptr, info_log);
        std::cout << "failed to link program\n";
        std::cout << "\tlog: " << info_log << '\n';
        throw std::runtime_error("failed to link program");
    }

    glDetachShader(program, vertex_shader);
    glDetachShader(program, fragment_shader);

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    return program;
}

unsigned int snake::make_program(
        const std::filesystem::path& vertex_shader_path,
        const std::filesystem::path& geometry_shader_path,
        const std::filesystem::path& fragment_shader_path) {

    auto vertex_shader = make_shader(GL_VERTEX_SHADER, vertex_shader_path);
    auto geometry_shader = make_shader(GL_GEOMETRY_SHADER, geometry_shader_path);
    auto fragment_shader = make_shader(GL_FRAGMENT_SHADER, fragment_shader_path);

    auto program = glCreateProgram();

    glAttachShader(program, vertex_shader);
    glAttachShader(program, geometry_shader);
    glAttachShader(program, fragment_shader);

    glLinkProgram(program);

    int success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        char info_log[512];
        glGetProgramInfoLog(program, 512, nullptr, info_log);
        std::cout << "failed to link program\n";
        std::cout << "\tlog: " << info_log << '\n';
        throw std::runtime_error("failed to link program");
    }

    glDetachShader(program, vertex_shader);
    glDetachShader(program, geometry_shader);
    glDetachShader(program, fragment_shader);

    glDeleteShader(vertex_shader);
    glDeleteShader(geometry_shader);
    glDeleteShader(fragment_shader);

    return program;
}
