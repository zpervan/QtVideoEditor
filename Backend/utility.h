#ifndef QTVIDEOEDITOR_BACKEND_UTILITY_H_
#define QTVIDEOEDITOR_BACKEND_UTILITY_H_

#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

static const fs::path kGRootFolderName{"QtVideoEditor"};

/// @brief Contains all auxiliary helper functions for generating and fetching
/// various paths of specific files and folders.
namespace utility::path {

/// @brief Creates a project root path.
fs::path CreateProjectRootPath() {
  fs::path root_folder_path;
  for (const auto &element : fs::current_path()) {
    if (element == kGRootFolderName) {
      root_folder_path.append(element.c_str());
      break;
    } else {
      root_folder_path.append(element.c_str());
    }
  }
  return root_folder_path;
}

/// @brief Creates a path to the video folder.
fs::path CreateAssetsVideoFolder() {
  return {CreateProjectRootPath().append("Assets/Video/")};
}

/// @brief Creates a path to the pictures folder.
fs::path CreateAssetsPictureFolder() {
  return {CreateProjectRootPath().append("Assets/Pictures/")};
}

} // namespace utility::path

#endif // QTVIDEOEDITOR_BACKEND_UTILITY_H_
