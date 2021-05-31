#ifndef QTVIDEOEDITOR_BACKEND_PATH_CREATOR_H_
#define QTVIDEOEDITOR_BACKEND_PATH_CREATOR_H_

#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

static const fs::path kGRootFolderName{"QtVideoEditor"};

/// @brief Contains all helper functions for generating and fetching of various
/// paths for specific files and folders.
namespace path_creator {

/// @brief Generates a project root path
/// @return Path of the project root
static fs::path ProjectRoot() {
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

/// @brief Creates a video folder path based on the project root path
/// @return Videos folder path
static fs::path VideoFolder() {
  return {ProjectRoot().append("Assets/Videos/")};
}

/// @brief Creates a thumbnails folder path based on the project root path
/// @return Path of the project root
static fs::path ThumbnailsFolder() {
  return {ProjectRoot().append("Assets/Thumbnails/")};
}

} // namespace path_creator

#endif // QTVIDEOEDITOR_BACKEND_PATH_CREATOR_H_
