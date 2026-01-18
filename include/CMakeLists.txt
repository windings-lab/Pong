# Headers
add_library(Pong_Headers INTERFACE)
file(GLOB Pong_INCLUDE_FILES
	 "${Pong_SOURCE_DIR}/include/*.h"
	 "${Pong_SOURCE_DIR}/include/rhi/*.h"
	 "${Pong_SOURCE_DIR}/include/game_objects/*.h"
)
target_sources(Pong PRIVATE ${Pong_INCLUDE_FILES})
target_include_directories(Pong_Headers INTERFACE
						   "$<BUILD_INTERFACE:${Pong_SOURCE_DIR}/include>"
)
target_link_libraries(Pong PUBLIC Pong_Headers)

# Utility
add_library(Pong_Utility INTERFACE)
file(GLOB Pong_UTILITY_HEADERS "${Pong_SOURCE_DIR}/include/utility/*.h")
target_sources(Pong PRIVATE ${Pong_UTILITY_HEADERS})
target_include_directories(Pong_Utility INTERFACE
						   "$<BUILD_INTERFACE:${Pong_SOURCE_DIR}/include/utility>"
)
target_link_libraries(Pong PRIVATE Pong_Utility)