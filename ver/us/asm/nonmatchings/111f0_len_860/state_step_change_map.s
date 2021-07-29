.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80098320
.word L800361B4_115B4, L80036208_11608, L80036244_11644, L800362F8_116F8, L8003637C_1177C, 0

.section .text

glabel state_step_change_map
/* 1157C 8003617C 3C03800A */  lui       $v1, %hi(D_800A0944)
/* 11580 80036180 84630944 */  lh        $v1, %lo(D_800A0944)($v1)
/* 11584 80036184 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 11588 80036188 AFBF0018 */  sw        $ra, 0x18($sp)
/* 1158C 8003618C AFB10014 */  sw        $s1, 0x14($sp)
/* 11590 80036190 2C620005 */  sltiu     $v0, $v1, 5
/* 11594 80036194 10400094 */  beqz      $v0, .L800363E8
/* 11598 80036198 AFB00010 */   sw       $s0, 0x10($sp)
/* 1159C 8003619C 00031080 */  sll       $v0, $v1, 2
/* 115A0 800361A0 3C01800A */  lui       $at, %hi(jtbl_80098320)
/* 115A4 800361A4 00220821 */  addu      $at, $at, $v0
/* 115A8 800361A8 8C228320 */  lw        $v0, %lo(jtbl_80098320)($at)
/* 115AC 800361AC 00400008 */  jr        $v0
/* 115B0 800361B0 00000000 */   nop
glabel L800361B4_115B4
/* 115B4 800361B4 0C00E64C */  jal       update_npcs
/* 115B8 800361B8 00000000 */   nop
/* 115BC 800361BC 0C037DD0 */  jal       update_player
/* 115C0 800361C0 00000000 */   nop
/* 115C4 800361C4 0C016754 */  jal       update_effects
/* 115C8 800361C8 00000000 */   nop
/* 115CC 800361CC 0C00B500 */  jal       update_cameras
/* 115D0 800361D0 00000000 */   nop
/* 115D4 800361D4 3C04800A */  lui       $a0, %hi(gMapTransitionAlpha)
/* 115D8 800361D8 24840940 */  addiu     $a0, $a0, %lo(gMapTransitionAlpha)
/* 115DC 800361DC 0C04E0AB */  jal       update_exit_map_screen_overlay
/* 115E0 800361E0 00000000 */   nop
/* 115E4 800361E4 00021400 */  sll       $v0, $v0, 0x10
/* 115E8 800361E8 1040007F */  beqz      $v0, .L800363E8
/* 115EC 800361EC 00000000 */   nop
/* 115F0 800361F0 3C03800A */  lui       $v1, %hi(D_800A0944)
/* 115F4 800361F4 24630944 */  addiu     $v1, $v1, %lo(D_800A0944)
/* 115F8 800361F8 94620000 */  lhu       $v0, ($v1)
/* 115FC 800361FC 24420001 */  addiu     $v0, $v0, 1
/* 11600 80036200 0800D8FA */  j         .L800363E8
/* 11604 80036204 A4620000 */   sh       $v0, ($v1)
glabel L80036208_11608
/* 11608 80036208 3C03800A */  lui       $v1, %hi(gOverrideFlags)
/* 1160C 8003620C 2463A650 */  addiu     $v1, $v1, %lo(gOverrideFlags)
/* 11610 80036210 8C620000 */  lw        $v0, ($v1)
/* 11614 80036214 34420008 */  ori       $v0, $v0, 8
/* 11618 80036218 0C018028 */  jal       nuContRmbForceStop
/* 1161C 8003621C AC620000 */   sw       $v0, ($v1)
/* 11620 80036220 3C04800A */  lui       $a0, %hi(D_800A0944)
/* 11624 80036224 24840944 */  addiu     $a0, $a0, %lo(D_800A0944)
/* 11628 80036228 94820000 */  lhu       $v0, ($a0)
/* 1162C 8003622C 24030004 */  addiu     $v1, $zero, 4
/* 11630 80036230 3C01800A */  lui       $at, %hi(D_800A0946)
/* 11634 80036234 A4230946 */  sh        $v1, %lo(D_800A0946)($at)
/* 11638 80036238 24420001 */  addiu     $v0, $v0, 1
/* 1163C 8003623C 0800D8FA */  j         .L800363E8
/* 11640 80036240 A4820000 */   sh       $v0, ($a0)
glabel L80036244_11644
/* 11644 80036244 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 11648 80036248 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 1164C 8003624C 8E020000 */  lw        $v0, ($s0)
/* 11650 80036250 80420071 */  lb        $v0, 0x71($v0)
/* 11654 80036254 10400003 */  beqz      $v0, .L80036264
/* 11658 80036258 00000000 */   nop
/* 1165C 8003625C 0C00CD3C */  jal       set_game_mode
/* 11660 80036260 24040011 */   addiu    $a0, $zero, 0x11
.L80036264:
/* 11664 80036264 3C11800A */  lui       $s1, %hi(D_800A0946)
/* 11668 80036268 26310946 */  addiu     $s1, $s1, %lo(D_800A0946)
/* 1166C 8003626C 86220000 */  lh        $v0, ($s1)
/* 11670 80036270 96230000 */  lhu       $v1, ($s1)
/* 11674 80036274 10400003 */  beqz      $v0, .L80036284
/* 11678 80036278 2462FFFF */   addiu    $v0, $v1, -1
/* 1167C 8003627C 0800D8FA */  j         .L800363E8
/* 11680 80036280 A6220000 */   sh       $v0, ($s1)
.L80036284:
/* 11684 80036284 8E020000 */  lw        $v0, ($s0)
/* 11688 80036288 A0400070 */  sb        $zero, 0x70($v0)
/* 1168C 8003628C 8E020000 */  lw        $v0, ($s0)
/* 11690 80036290 A0400078 */  sb        $zero, 0x78($v0)
/* 11694 80036294 8E020000 */  lw        $v0, ($s0)
/* 11698 80036298 84440086 */  lh        $a0, 0x86($v0)
/* 1169C 8003629C 8445008C */  lh        $a1, 0x8c($v0)
/* 116A0 800362A0 0C0169BD */  jal       load_map_by_IDs
/* 116A4 800362A4 0000302D */   daddu    $a2, $zero, $zero
/* 116A8 800362A8 0C009C22 */  jal       set_time_freeze_mode
/* 116AC 800362AC 0000202D */   daddu    $a0, $zero, $zero
/* 116B0 800362B0 0C018030 */  jal       nuContRmbForceStopEnd
/* 116B4 800362B4 00000000 */   nop
/* 116B8 800362B8 8E020000 */  lw        $v0, ($s0)
/* 116BC 800362BC 80420071 */  lb        $v0, 0x71($v0)
/* 116C0 800362C0 14400003 */  bnez      $v0, .L800362D0
/* 116C4 800362C4 00000000 */   nop
/* 116C8 800362C8 0C03805E */  jal       disable_player_input
/* 116CC 800362CC 00000000 */   nop
.L800362D0:
/* 116D0 800362D0 0C00B500 */  jal       update_cameras
/* 116D4 800362D4 00000000 */   nop
/* 116D8 800362D8 3C02800A */  lui       $v0, %hi(D_800A0944)
/* 116DC 800362DC 24420944 */  addiu     $v0, $v0, %lo(D_800A0944)
/* 116E0 800362E0 94430000 */  lhu       $v1, ($v0)
/* 116E4 800362E4 24040002 */  addiu     $a0, $zero, 2
/* 116E8 800362E8 A6240000 */  sh        $a0, ($s1)
/* 116EC 800362EC 24630001 */  addiu     $v1, $v1, 1
/* 116F0 800362F0 0800D8FA */  j         .L800363E8
/* 116F4 800362F4 A4430000 */   sh       $v1, ($v0)
glabel L800362F8_116F8
/* 116F8 800362F8 0C00F949 */  jal       update_encounters
/* 116FC 800362FC 00000000 */   nop
/* 11700 80036300 0C00E64C */  jal       update_npcs
/* 11704 80036304 00000000 */   nop
/* 11708 80036308 0C037DD0 */  jal       update_player
/* 1170C 8003630C 00000000 */   nop
/* 11710 80036310 0C00B500 */  jal       update_cameras
/* 11714 80036314 00000000 */   nop
/* 11718 80036318 3C04800A */  lui       $a0, %hi(D_800A0946)
/* 1171C 8003631C 24840946 */  addiu     $a0, $a0, %lo(D_800A0946)
/* 11720 80036320 84820000 */  lh        $v0, ($a0)
/* 11724 80036324 94830000 */  lhu       $v1, ($a0)
/* 11728 80036328 10400003 */  beqz      $v0, .L80036338
/* 1172C 8003632C 2462FFFF */   addiu    $v0, $v1, -1
/* 11730 80036330 0800D8FA */  j         .L800363E8
/* 11734 80036334 A4820000 */   sh       $v0, ($a0)
.L80036338:
/* 11738 80036338 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 1173C 8003633C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 11740 80036340 0C0B1059 */  jal       does_script_exist
/* 11744 80036344 8C44006C */   lw       $a0, 0x6c($v0)
/* 11748 80036348 14400027 */  bnez      $v0, .L800363E8
/* 1174C 8003634C 2405FFF7 */   addiu    $a1, $zero, -9
/* 11750 80036350 3C04800A */  lui       $a0, %hi(gOverrideFlags)
/* 11754 80036354 2484A650 */  addiu     $a0, $a0, %lo(gOverrideFlags)
/* 11758 80036358 3C06800A */  lui       $a2, %hi(D_800A0944)
/* 1175C 8003635C 24C60944 */  addiu     $a2, $a2, %lo(D_800A0944)
/* 11760 80036360 8C820000 */  lw        $v0, ($a0)
/* 11764 80036364 94C30000 */  lhu       $v1, ($a2)
/* 11768 80036368 00451024 */  and       $v0, $v0, $a1
/* 1176C 8003636C 24630001 */  addiu     $v1, $v1, 1
/* 11770 80036370 AC820000 */  sw        $v0, ($a0)
/* 11774 80036374 0800D8FA */  j         .L800363E8
/* 11778 80036378 A4C30000 */   sh       $v1, ($a2)
glabel L8003637C_1177C
/* 1177C 8003637C 0C00E64C */  jal       update_npcs
/* 11780 80036380 00000000 */   nop
/* 11784 80036384 0C037DD0 */  jal       update_player
/* 11788 80036388 00000000 */   nop
/* 1178C 8003638C 0C016754 */  jal       update_effects
/* 11790 80036390 00000000 */   nop
/* 11794 80036394 0C00B500 */  jal       update_cameras
/* 11798 80036398 00000000 */   nop
/* 1179C 8003639C 3C04800A */  lui       $a0, %hi(gMapTransitionAlpha)
/* 117A0 800363A0 24840940 */  addiu     $a0, $a0, %lo(gMapTransitionAlpha)
/* 117A4 800363A4 0C04E175 */  jal       update_enter_map_screen_overlay
/* 117A8 800363A8 00000000 */   nop
/* 117AC 800363AC 00021400 */  sll       $v0, $v0, 0x10
/* 117B0 800363B0 1040000D */  beqz      $v0, .L800363E8
/* 117B4 800363B4 00000000 */   nop
/* 117B8 800363B8 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 117BC 800363BC 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 117C0 800363C0 80420071 */  lb        $v0, 0x71($v0)
/* 117C4 800363C4 14400003 */  bnez      $v0, .L800363D4
/* 117C8 800363C8 00000000 */   nop
/* 117CC 800363CC 0C038069 */  jal       enable_player_input
/* 117D0 800363D0 00000000 */   nop
.L800363D4:
/* 117D4 800363D4 3C05BF80 */  lui       $a1, 0xbf80
/* 117D8 800363D8 0C04DF62 */  jal       set_screen_overlay_params_front
/* 117DC 800363DC 240400FF */   addiu    $a0, $zero, 0xff
/* 117E0 800363E0 0C00CD3C */  jal       set_game_mode
/* 117E4 800363E4 24040004 */   addiu    $a0, $zero, 4
.L800363E8:
/* 117E8 800363E8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 117EC 800363EC 8FB10014 */  lw        $s1, 0x14($sp)
/* 117F0 800363F0 8FB00010 */  lw        $s0, 0x10($sp)
/* 117F4 800363F4 03E00008 */  jr        $ra
/* 117F8 800363F8 27BD0020 */   addiu    $sp, $sp, 0x20
