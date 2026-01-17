#include "frames_content.h"

frames_content::frames_content(const QString& file, const QString& con) noexcept: file_type(std::move(file)), constructor_string(std::move(con)) {}
frames_content::frames_content(const frames_content& other) noexcept: file_type(other.file_type), constructor_string(other.constructor_string) {}