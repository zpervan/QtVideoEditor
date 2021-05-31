#ifndef QTVIDEOEDITOR_BACKEND_PATH_CREATOR_H_
#define QTVIDEOEDITOR_BACKEND_PATH_CREATOR_H_

#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

static const fs::path kGRootFolderName{"QtVideoEditor"};

/// @brief Contains all auxiliary helper functions for generating and fetching
/// various paths of specific files and folders.
namespace path_creator {

/// @brief Creates a project root path.
static fs::path ProjectRootPath() {
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
static fs::path VideoFolder() {
  return {ProjectRootPath().append("Assets/Videos/")};
}

/// @brief Creates a path to the pictures folder.
static fs::path PictureFolder() {
  return {ProjectRootPath().append("Assets/Thumbnails/")};
}

} // namespace path

#endif // QTVIDEOEDITOR_BACKEND_PATH_CREATOR_H_
