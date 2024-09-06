#include <ncurses.h>

/// An enumeration for handling keystrokes. It is necessary to simplify the
/// handling of pressed keys and make it easier to change keyboard shortcuts
enum class Action {
  MOVE_LEFT,  ///< Cursor movement left
  MOVE_DOWN,  ///< Cursor movement down
  MOVE_UP,    ///< Cursor movement up
  MOVE_RIGHT, ///< Cursor movement right
  SWITCH,     ///< Cell type switching
  UNKNOWN,    ///< Unknown key
};

/// Keystroke handler
///
/// The character passed is translated into an [`Action`] enumeration object
///
/// @param[in] key Symbol to be processed
///
/// @return Type of event processed
Action key_handler(char key) {
  switch (key) {
  case 104:      // h
  case KEY_LEFT: // left arrow
    return Action::MOVE_LEFT;
    break;
  case 106:
  case KEY_DOWN:
    return Action::MOVE_DOWN;
    break;
  case 107:
  case KEY_UP:
    return Action::MOVE_UP;
    break;
  case 108:
  case KEY_RIGHT:
    return Action::MOVE_RIGHT;
    break;
  default:
    return Action::UNKNOWN;
    break;
  }
}
