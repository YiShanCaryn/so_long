so_long
=======

A compact 2D maze game written in C using MiniLibX (X11) and a bundled `libft`. The goal is simple: collect all fish (`C`) and reach the exit (`E`). This README expands on build steps, runtime details, map rules, and developer notes so you or other contributors can run and modify the project easily.

## Quick start

Build and run the example map:

```bash
make
./so_long game_maps/test.ber
```

If you prefer a clean rebuild:

```bash
make fclean
make
```

## What this project contains

- `Makefile` — top-level build rules. Builds `libft` then links the game with the bundled MLX.
- `game_code/` — all game C sources and `so_long.h`.
- `game_images/` — XPM sprite assets used in the game.
- `game_maps/` — example `.ber` maps and test maps.
- `libft/` — bundled libft implementation and its `Makefile`.
- `mlx_linux/` — MLX sources and prebuilt libs for Linux.

## System requirements (Linux)

- gcc (or another C compiler compatible with the code)
- make
- X11 development headers and libraries (libX11, libXext). On Debian/Ubuntu, install:

```bash
sudo apt-get install build-essential libx11-dev libxext-dev libxrandr-dev libxinerama-dev libxft-dev libxss-dev zlib1g-dev
```

- Some systems may need additional development packages for MLX. The `Makefile` links `-lX11 -lXext -lm -lz`.

## Build details (what the Makefile does)

- `CC = gcc` and `CFLAGS = -Wall -Wextra -Werror -Igame_code -Ilibft -Imlx_linux -I/usr/include -O3`.
- The main target `so_long` compiles object files from `game_code/*` and links against `libft/libft.a` and MLX (from `mlx_linux`).
- `make` calls `make -C libft` to build the bundled library before linking.

If you need to change compilation flags (for debugging, e.g. `-g`), edit `CFLAGS` in `Makefile`.

## Usage and command-line

Run:

```bash
./so_long path/to/map.ber
```

Notes:
- The program requires exactly one argument (a `.ber` map file). If not provided it prints:

```
Error
This programe take 1 argument .ber
```

- If file extension is not `.ber` the program prints:

```
Error
No correct format map found
```

## Controls (in-game)

- Move Up: W or Up arrow (XK_w or XK_Up)
- Move Down: S or Down arrow (XK_s or XK_Down)
- Move Left: A or Left arrow (XK_a or XK_Left)
- Move Right: D or Right arrow (XK_d or XK_Right)
- Quit: Escape (XK_Escape) or close window

Console messages you will see:

- Step count: N
- Fish collected! Total: X/Y
- Exit unlocked! 🎉
- Game Over! You Win! 🎉

## Map format and validation (detailed)

Maps are text files with extension `.ber`. The parser performs several checks; a map must pass all of them to run:

1. File extension must be `.ber` (checked by `format_check`).
2. The map is read into lines and split on `\n` — empty lines inside the map will cause an error (the reader treats a blank line as invalid).
3. Rectangle check: every row must be the same length (`ft_check_format`).
4. Border check: the first and last rows must be all `1` (`ft_check_top_bottom`), and each row must start and end with `1` (`ft_check_sides`).
5. Allowed characters (`ft_check_valid_chars`): only `1`, `0`, `C`, `P`, `E`.
6. Content check (`ft_check_map`): exactly 1 player `P`, exactly 1 exit `E`, and at least 1 collectible `C`.
7. Reachability check (`path_valid`) — a flood-fill is performed to ensure all `C` and the `E` are reachable from `P` (so the map is solvable).

Common failure messages and causes:

- "Map must be a rectangle or a square" — rows are of different lengths.
- "Wall not properly enclosed on top/bottom" — top/bottom row contains a non-`1` character.
- "Side walls are not properly enclosed" — a row's first or last character is not `1`.
- "Invalid map" — invalid character present.
- "Need 1 Player/Exit/1 Object that are accessible" — wrong counts or unreachable objects.

Example valid map (from `game_maps/test.ber`):

```
1111111111111111
1P00001000000C01
1111000000000111
10000000C0010001
1000C10000011111
100001001000C001
1000010C100000E1
1111111111111111
```

## Code structure (important files)

- `game_code/so_long.c` — program entry, argument parsing and main flow.
- `game_code/map_reader.c` — reading the `.ber` file into memory and orchestrating checks.
- `game_code/map_check.c` — validation helpers (format, borders, characters, counts).
- `game_code/floodfill_check.c` — (path_valid/copy_map) ensures reachability of collectibles and exit.
- `game_code/window_reader.c` — converts map characters into drawn images and owns the main MLX loop.
- `game_code/move_check.c` & `game_code/movement.c` — key handler and movement logic (collision, collectibles, win condition).
- `game_code/setting.c` & `set_img` — image path setup and image loading into MLX textures.
- `game_images/` — assets (XPM files) loaded at runtime.

If you want to change input mapping or add features, start by editing `move_check.c` and `movement.c`.

## Developer notes / how to add content

- Add a new map: place a `.ber` file in `game_maps/` and ensure it follows the format rules above.
- Add/change sprites: replace or add XPM files in `game_images/` and update `set_img` if paths or names change.
- Enable debug-friendly compilation: set `CFLAGS` in `Makefile` to include `-g` and remove `-O3` for easier stepping.

## Testing maps quickly

1. Build `make`.
2. Run `./so_long game_maps/test.ber` and verify the window opens and you can move.
3. Try the intentionally invalid maps under `game_maps/` (e.g. `no_collect.ber`, `no_exit.ber`) to verify parser error messages.

## Troubleshooting (expanded)

- "No correct format map found": supply a `.ber` filename.
- "Map not valid.": The reader will free remaining lines and exit when encountering an internal blank line.
- Window creation failures: ensure `mlx_init()` returns a valid pointer — usually missing X11 headers or running without an X server causes this.
- Linker errors for MLX: confirm `mlx_linux/` is compiled and `Makefile` links `-lmlx_Linux -lXext -lX11 -lm -lz`.

If you need help diagnosing a specific compiler or runtime error, copy the exact message and I can help interpret it.

## Contributing

- This is a personal/educational project. If you want to contribute, open a PR with a clear description. Keep changes small (one feature or bugfix per PR).
- If adding public-facing features, add/update tests and a short usage example.

## License

No license file included. Add a `LICENSE` file if you want to define reuse terms.

---

If you'd like I can also:
- commit the README changes to git for you (I can run the git commands if you want);
- add a short example GIF/screenshot section (you'll need to provide the image file);
- add a `DEV_NOTES.md` with a short contributor checklist and code pointers.
