//
// Created by asuka on 09.03.2023.
//

# ifndef SNAKE_MAKE_PROGRAM_HPP
# define SNAKE_MAKE_PROGRAM_HPP

# include <filesystem>

namespace snake {

    unsigned int make_program(
            const std::filesystem::path& vertex_shader_path,
            const std::filesystem::path& fragment_shader_path);

    unsigned int make_program(
            const std::filesystem::path& vertex_shader_path,
            const std::filesystem::path& geometry_shader_path,
            const std::filesystem::path& fragment_shader_path);

}

# endif // SNAKE_MAKE_PROGRAM_HPP
