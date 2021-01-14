#!/usr/bin/env python3

import re
import os, sys
from glob import glob
import ninja_syntax
from argparse import ArgumentParser
import asyncio
from subprocess import PIPE

sys.path.append(os.path.dirname(__file__) + "/tools/n64splat")
import split

INCLUDE_ASM_RE = re.compile(r"_INCLUDE_ASM\([^,]+, ([^,]+), ([^,)]+)") # note _ prefix
CPPFLAGS = "-Iinclude -Isrc -D _LANGUAGE_C -D _FINALROM -ffreestanding -DF3DEX_GBI_2 -D_MIPS_SZLONG=32"

NPC_SPRITES = "world_goombario world_kooper world_bombette world_parakarry world_bow world_watt world_sushie world_lakilester battle_goombario battle_kooper battle_bombette battle_parakarry battle_bow battle_watt battle_sushie battle_lakilester kooper_without_shell world_eldstar world_mamar world_skolar world_muskular world_misstar world_klevar world_kalmar battle_eldstar battle_mamar battle_skolar battle_muskular battle_misstar battle_klevar battle_kalmar twink jr_troopa spiked_jr_troopa spiked_para_jr_troopa mage_jr_troopa para_jr_troopa goomba spiked_goomba paragoomba koopa_troopa para_troopa fuzzy bob_omb bullet_bill bill_blaster monty_mole cleft pokey battle_bandit buzzy_beetle swooper stone_chomp putrid_piranha piranha_plant sentinel world_clubba battle_clubba shy_guy groove_guy sky_guy pyro_guy spy_guy medi_guy fuzzipede jungle_guy heart_plant hurt_plant m_bush bubble kent_c_koopa dayzee lakitu spiny bzzap ruff_puff spike_top duplighost albino_dino blooper baby_blooper gulpit dry_bones thrown_bone bony_beetle magikoopa flying_magikoopa world_koopatrol koopatrol hammer_bros bush_basic bush_blocky bush_dry bush_leafy bush_matted world_kammy battle_kammy goomba_bros goomba_king spiky_goomnut dark_toad koopa_bros buzzar tutankoopa chain_chomp world_tubba battle_tubba tubbas_heart big_lantern_ghost shy_squad_guy marshal_guy stilt_guy stilt_guy_unfold shy_stack_guy shy_stack_unfold shy_stack_damage shy_stack_rock general_guy general_guy_bomb tank_guy lava_piranha_head petit_piranha lava_bud huff_n_puff tuff_puff monstar crystal_king world_bowser battle_bowser luigi toad three_sisters vanna_t toad_kid toad_guard harry_t toad_minister postmaster conductor_toad train_station_toad fishmael artist_toad koopa koopa_without_shell world_bob_omb whacka dryite mouser boo yoshi yoshi_kid raven bubulb penguin shiver_toad world_bandit goompa goombaria gooma goompapa goomama the_master chan lee merlon chet_rippo rowf minh_t russ_t tayce_t fice_t bartender chanterelle rip_cheato chuck_quizmo merluvlee merlar merlow star_kid kolorado_wife koopa_koot kolorado battle_kolorado archeologist nomadimouse world_merlee battle_merlee disguised_moustafa moustafa oaklie bootler yakkey gourmet_guy village_leader leaders_friend rafael_raven tolielup gate_flower petunia posie lily rosie sun lakilulu ninji mayor_penguin mayor_penguin_wife penguin_patrol herringway merle star_rod fire coin parade_peach parade_koopas parade_burnt_bowser parade_luigi parade_partners parade_yoshis parade_kolorados parade_chicks parade_ice_show parade_toads parade_batons parade_drums parade_flags parade_horns parade_tubba_balloon parade_wizards parade_mario parade_shy_guys parade_twink leaf".split(" ")

def obj(path: str):
    if not path.startswith("$builddir/"):
        path = "$builddir/" + path
    return path + ".o"

def read_splat(splat_config: str):
    import argparse
    import yaml

    # Load config
    with open(splat_config) as f:
        config = yaml.safe_load(f.read())

    options = config.get("options")
    assert options.get("ld_o_replace_extension", True) == False

    # Initialize segments
    all_segments = split.initialize_segments(options, splat_config, config["segments"])

    objects = set()
    segments = {}

    for segment in all_segments:
        for subdir, path, obj_type, start in segment.get_ld_files():
            path = subdir + "/" + path

            objects.add(path)
            segments[path] = segment

    # note: `objects` lacks .o extensions
    return objects, segments

async def shell(cmd: str):
    async with task_sem:
        proc = await asyncio.create_subprocess_shell(cmd, stdout=PIPE, stderr=PIPE)
        stdout, stderr = await proc.communicate()

    assert proc.returncode == 0, f"{cmd} failed: {stderr}"

    return stdout.decode("utf-8"), stderr.decode("utf-8")

async def task(coro):
    global num_tasks, num_tasks_done

    await coro

    num_tasks_done += 1
    print(f"\r{(num_tasks_done / num_tasks) * 100:.0f}%", end="")

async def build_c_file(c_file: str, generated_headers):
    # preprocess c_file, but simply put an _ in front of INCLUDE_ASM and SCRIPT
    stdout, stderr = await shell(f"{cpp} {CPPFLAGS} '-DINCLUDE_ASM(...)=_INCLUDE_ASM(__VA_ARGS__)' '-DSCRIPT(...)=_SCRIPT(__VA_ARGS__)' {c_file} -o -")

    # search for macro usage (note _ prefix)
    uses_dsl = "_SCRIPT(" in stdout

    s_deps = []
    for line in stdout.splitlines():
        if line.startswith("_INCLUDE_ASM"):
            match = INCLUDE_ASM_RE.match(line)
            if match:
                s_deps.append("asm/nonmatchings/" + eval(match[1]) + "/" + match[2] + ".s")

    # add build task to ninja
    n.build(obj(c_file), "cc_dsl" if uses_dsl else "cc", c_file, implicit=s_deps, order_only=generated_headers)

def build_yay0_file(bin_file: str):
    yay0_file = f"$builddir/{os.path.splitext(bin_file)[0]}.Yay0"
    n.build(yay0_file, "yay0compress", bin_file, implicit=["tools/Yay0compress"])
    build_bin_object(yay0_file)

def build_bin_object(bin_file: str):
    n.build(obj(bin_file), "bin", bin_file)

def build_image(f: str, segment):
    path, img_type, png = f.rsplit(".", 2)
    out = "$builddir/" + path + "." + img_type + ".png"

    flags = ""
    if img_type != "palette":
        if segment.flip_horizontal:
            flags += "--flip-x"
        if segment.flip_vertical:
            flags += "--flip-y"

    n.build(out, "img", path + ".png", implicit="tools/convert_image.py", variables={
        "img_type": img_type,
        "img_flags": flags,
    })
    build_bin_object(out)

async def main():
    global n, cpp, task_sem, num_tasks, num_tasks_done

    parser = ArgumentParser(description="Generates build.ninja")
    parser.add_argument("--cpp", help="C preprocessor command")
    args = parser.parse_args()

    # on macOS, /usr/bin/cpp defaults to clang rather than gcc (but we need gcc's)
    if args.cpp is None and sys.platform == "darwin" and "Free Software Foundation" not in await shell("cpp --version")[0]:
        print("error: use 'brew' to obtain GNU cpp and run again with '--cpp cpp-10'")
        exit(1)

    cpp = args.cpp or "cpp"
    task_sem = asyncio.Semaphore(8)

    # compile n64splat dependencies
    await shell("make -C tools/n64splat")

    # split assets
    split.main(
        "baserom.z64",
        "tools/splat.yaml",
        ".",
        [ "ld", "bin", "Yay0", "PaperMarioMapFS", "PaperMarioMessages", "img", "PaperMarioNpcSprites" ],
        False,
        False,
    )

    # generate build.ninja
    n = ninja_syntax.Writer(open("build.ninja", "w"), width=120)

    n.variable("builddir", "build")
    n.variable("target", "papermario")
    n.variable("cross", "mips-linux-gnu-")
    n.variable("python", sys.executable)
    n.variable("os", "mac" if sys.platform == "darwin" else "linux")
    n.variable("iconv", "tools/iconv.py UTF-8 SHIFT-JIS" if sys.platform == "darwin" else "iconv --from UTF-8 --to SHIFT-JIS")
    n.variable("cppflags", f"{CPPFLAGS} -Wcomment")
    n.variable("cflags", "-O2 -quiet -G 0 -mcpu=vr4300 -mfix4300 -mips3 -mgp32 -mfp32 -Wuninitialized -Wshadow")
    n.newline()

    n.rule("cc",
        command=f"{cpp} $cppflags $in -o - | $iconv | tools/$os/cc1 $cflags -o - | tools/$os/mips-nintendo-nu64-as -EB -G 0 - -o $out",
        description="cc $in",
        depfile="$out.d",
        deps="gcc")
    n.rule("cc_dsl",
        command=f"{cpp} $cppflags $in -o - | $python tools/compile_dsl_macros.py | $iconv | tools/$os/cc1 $cflags -o - | tools/$os/mips-nintendo-nu64-as -EB -G 0 - -o $out",
        description="cc (with dsl) $in",
        depfile="$out.d",
        deps="gcc")
    n.newline()

    n.rule("cpp",
        command=f"{cpp} -P -DBUILD_DIR=$builddir $in -o $out",
        description="cc (with dsl) $in",
        depfile="$out.d",
        deps="gcc")
    n.newline()

    n.rule("yay0compress",
        command=f"tools/Yay0compress $in $out",
        description="compress $in")
    n.newline()

    n.rule("bin",
        command="${cross}ld -r -b binary $in -o $out",
        description="bin $in")
    n.newline()

    n.rule("as",
        command="${cross}as -EB -march=vr4300 -mtune=vr4300 -Iinclude $in -o $out",
        description="assemble $in")
    n.newline()

    # $img_type, $img_flags
    n.rule("img",
        command="$python tools/convert_image.py $img_type $in $out $img_flags",
        description="image $in")
    n.newline()

    # $sprite_id, $sprite_dir, $sprite_name
    n.rule("sprite_animations_h",
        command="$python tools/gen_sprite_animations_h.py $out $sprite_dir $sprite_id",
        description="sprite_animations_h $sprite_name ($sprite_id)")
    n.rule("npc_sprite",
        command="$python tools/compile_npc_sprite.py $out $sprite_dir",
        description="npc_sprite $sprite_name ($sprite_id)")
    n.rule("npc_sprites",
        command="$python tools/compile_npc_sprites.py $out $in",
        description="package npc sprites")
    n.newline()

    n.rule("ld_addrs_h",
        command="grep -E \"[^\. ]+ =\" $in -o | sed 's/^/extern void* /; s/ =/;/' > $out",
        description="ld_addrs_h $in")
    n.newline()

    # $msg_combine_headers
    n.rule("msg_combine",
        command="$python tools/msg/combine.py $out $in --headers $msg_combine_headers",
        description="combine messages")
    n.rule("msg",
        command="$python tools/msg/parse_compile.py $in $out",
        description="msg $in")
    n.newline()

    objects, segments = read_splat("tools/splat.yaml") # no .o extensions!
    c_files = (f for f in objects if f.endswith(".c")) # glob("src/**/*.c", recursive=True)

    n.comment("target")
    n.build("$builddir/$target.ld", "cpp", "$target.ld")
    # TODO ...
    n.newline()

    # generated headers
    n.comment("generated headers")
    generated_headers = []

    def add_generated_header(h: str):
        generated_headers.append(h)

        if not os.path.exists(h):
            # mkdir -p
            os.makedirs(os.path.dirname(h), exist_ok=True)

            # touch it so cpp doesn't complain if its #included
            open(h, "w").close()

            # mark it as really old so ninja builds it
            os.utime(h, (0, 0))

        return h

    n.build(add_generated_header("include/ld_addrs.h"), "ld_addrs_h", "$builddir/$target.ld")

    # messages
    msg_files = glob("src/**/*.msg", recursive=True) + glob("msg/**/*.msg", recursive=True)
    for msg_file in msg_files:
        n.build(
            f"$builddir/{msg_file}.bin",
            "msg",
            msg_file,
            implicit="tools/msg/parse_compile.py",
        )
    n.build(
        "$builddir/msg.bin",
        "msg_combine",
        [f"$builddir/{msg_file}.bin" for msg_file in msg_files],
        implicit="tools/msg/combine.py",
        implicit_outputs=[add_generated_header(f"{msg_file}.h") for msg_file in msg_files],
        variables={ "msg_combine_headers": [f"{msg_file}.h" for msg_file in msg_files] }
    )
    n.build("$builddir/msg.o", "bin", "$builddir/msg.bin")

    # sprites
    npc_sprite_yay0s = []
    for sprite_id, sprite_name in enumerate(NPC_SPRITES, 1):
        sources = glob(f"sprite/npc/{sprite_name}/**/*.*", recursive=True)
        variables = {
            "sprite_name": sprite_name,
            "sprite_dir": f"sprite/npc/{sprite_name}",
            "sprite_id": sprite_id,
        }

        # generated header
        n.build(
            add_generated_header(f"include/sprite/npc/{sprite_name}.h"),
            "sprite_animations_h",
            implicit=sources + ["tools/gen_sprite_animations_h.py"],
            variables=variables,
        )

        # sprite bin/yay0
        n.build(
            f"$builddir/sprite/npc/{sprite_name}",
            "npc_sprite",
            implicit=sources + ["tools/compile_npc_sprite.py"],
            variables=variables,
        )
        yay0 = f"$builddir/sprite/npc/{sprite_name}.Yay0"
        npc_sprite_yay0s.append(yay0)
        n.build(
            yay0,
            "yay0compress",
            f"$builddir/sprite/npc/{sprite_name}",
            implicit=["tools/Yay0compress"],
        )

    n.newline()

    # fast tasks
    n.comment("data")
    for f in objects:
        segment = segments[f]

        if f.endswith(".c"):
            continue # these are handled later
        elif f.endswith(".Yay0"):
            build_yay0_file(os.path.splitext(f)[0] + ".bin")
        elif f.endswith(".bin"):
            build_bin_object(f)
        elif f.endswith(".data"):
            n.build(obj(f), "as", "asm/" + f + ".s")
        elif f.endswith(".rodata"):
            n.build(obj(f), "as", "asm/" + f[2:] + ".s")
        elif f.endswith(".s"):
            n.build(obj(f), "as", f)
        elif f.endswith(".png"):
            build_image(f, segment)
        elif f == "sprite/npc":
            # combine sprites
            n.build(f"$builddir/{f}.bin", "npc_sprites", npc_sprite_yay0s, implicit="tools/compile_npc_sprites.py")
            n.build(obj(f), "bin", f"$builddir/{f}.bin")
        elif f == "/msg":
            continue # done already above
        else:
            print("warning: dont know what to do with object " + f)
    n.newline()

    # slow tasks generated concurrently
    n.comment("c")
    tasks = [task(build_c_file(f, generated_headers)) for f in c_files]
    num_tasks = len(tasks)
    num_tasks_done = 0
    await asyncio.gather(*tasks)
    print("")
    n.newline()

    n.rule("cc_modern_exe", command="cc $in -O3 -o $out")
    n.build("tools/Yay0compress", "cc_modern_exe", "tools/Yay0compress.c")

if __name__ == "__main__":
    asyncio.run(main())
