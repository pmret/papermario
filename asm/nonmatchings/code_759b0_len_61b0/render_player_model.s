.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel render_player_model
/* 7A618 800E1168 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 7A61C 800E116C AFB10044 */  sw        $s1, 0x44($sp)
/* 7A620 800E1170 AFB00040 */  sw        $s0, 0x40($sp)
/* 7A624 800E1174 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* 7A628 800E1178 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* 7A62C 800E117C AFBF0048 */  sw        $ra, 0x48($sp)
/* 7A630 800E1180 8E030000 */  lw        $v1, ($s0)
/* 7A634 800E1184 3C024000 */  lui       $v0, 0x4000
/* 7A638 800E1188 00621024 */  and       $v0, $v1, $v0
/* 7A63C 800E118C 10400054 */  beqz      $v0, .L800E12E0
/* 7A640 800E1190 27B10020 */   addiu    $s1, $sp, 0x20
/* 7A644 800E1194 3C02BFFF */  lui       $v0, 0xbfff
/* 7A648 800E1198 3442FFFF */  ori       $v0, $v0, 0xffff
/* 7A64C 800E119C 8E050028 */  lw        $a1, 0x28($s0)
/* 7A650 800E11A0 8E06002C */  lw        $a2, 0x2c($s0)
/* 7A654 800E11A4 8E070030 */  lw        $a3, 0x30($s0)
/* 7A658 800E11A8 3C04800A */  lui       $a0, %hi(D_8009A634)
/* 7A65C 800E11AC 8484A634 */  lh        $a0, %lo(D_8009A634)($a0)
/* 7A660 800E11B0 00621024 */  and       $v0, $v1, $v0
/* 7A664 800E11B4 AE020000 */  sw        $v0, ($s0)
/* 7A668 800E11B8 27A20030 */  addiu     $v0, $sp, 0x30
/* 7A66C 800E11BC AFA20010 */  sw        $v0, 0x10($sp)
/* 7A670 800E11C0 27A20034 */  addiu     $v0, $sp, 0x34
/* 7A674 800E11C4 AFA20014 */  sw        $v0, 0x14($sp)
/* 7A678 800E11C8 27A20038 */  addiu     $v0, $sp, 0x38
/* 7A67C 800E11CC 0C00B94E */  jal       get_screen_coords
/* 7A680 800E11D0 AFA20018 */   sw       $v0, 0x18($sp)
/* 7A684 800E11D4 8E020000 */  lw        $v0, ($s0)
/* 7A688 800E11D8 3C030002 */  lui       $v1, 2
/* 7A68C 800E11DC 00431024 */  and       $v0, $v0, $v1
/* 7A690 800E11E0 14400026 */  bnez      $v0, .L800E127C
/* 7A694 800E11E4 24020011 */   addiu    $v0, $zero, 0x11
/* 7A698 800E11E8 9203000E */  lbu       $v1, 0xe($s0)
/* 7A69C 800E11EC 9202000F */  lbu       $v0, 0xf($s0)
/* 7A6A0 800E11F0 1062001F */  beq       $v1, $v0, .L800E1270
/* 7A6A4 800E11F4 2C6200FE */   sltiu    $v0, $v1, 0xfe
/* 7A6A8 800E11F8 10400011 */  beqz      $v0, .L800E1240
/* 7A6AC 800E11FC 3C030100 */   lui      $v1, 0x100
/* 7A6B0 800E1200 8E020004 */  lw        $v0, 4($s0)
/* 7A6B4 800E1204 00431024 */  and       $v0, $v0, $v1
/* 7A6B8 800E1208 14400002 */  bnez      $v0, .L800E1214
/* 7A6BC 800E120C 24080016 */   addiu    $t0, $zero, 0x16
/* 7A6C0 800E1210 24080011 */  addiu     $t0, $zero, 0x11
.L800E1214:
/* 7A6C4 800E1214 0000202D */  daddu     $a0, $zero, $zero
/* 7A6C8 800E1218 2405FFFF */  addiu     $a1, $zero, -1
/* 7A6CC 800E121C 24060007 */  addiu     $a2, $zero, 7
/* 7A6D0 800E1220 9202000E */  lbu       $v0, 0xe($s0)
/* 7A6D4 800E1224 0080382D */  daddu     $a3, $a0, $zero
/* 7A6D8 800E1228 A20800BE */  sb        $t0, 0xbe($s0)
/* 7A6DC 800E122C AFA00010 */  sw        $zero, 0x10($sp)
/* 7A6E0 800E1230 AFA00014 */  sw        $zero, 0x14($sp)
/* 7A6E4 800E1234 AFA0001C */  sw        $zero, 0x1c($sp)
/* 7A6E8 800E1238 0803849A */  j         .L800E1268
/* 7A6EC 800E123C AFA20018 */   sw       $v0, 0x18($sp)
.L800E1240:
/* 7A6F0 800E1240 0000202D */  daddu     $a0, $zero, $zero
/* 7A6F4 800E1244 2405FFFF */  addiu     $a1, $zero, -1
/* 7A6F8 800E1248 0080302D */  daddu     $a2, $a0, $zero
/* 7A6FC 800E124C 0080382D */  daddu     $a3, $a0, $zero
/* 7A700 800E1250 2402000D */  addiu     $v0, $zero, 0xd
/* 7A704 800E1254 A20200BE */  sb        $v0, 0xbe($s0)
/* 7A708 800E1258 AFA00010 */  sw        $zero, 0x10($sp)
/* 7A70C 800E125C AFA00014 */  sw        $zero, 0x14($sp)
/* 7A710 800E1260 AFA00018 */  sw        $zero, 0x18($sp)
/* 7A714 800E1264 AFA0001C */  sw        $zero, 0x1c($sp)
.L800E1268:
/* 7A718 800E1268 0C0B77B9 */  jal       func_802DDEE4
/* 7A71C 800E126C 00000000 */   nop
.L800E1270:
/* 7A720 800E1270 9202000E */  lbu       $v0, 0xe($s0)
/* 7A724 800E1274 080384A1 */  j         .L800E1284
/* 7A728 800E1278 A202000F */   sb       $v0, 0xf($s0)
.L800E127C:
/* 7A72C 800E127C A20200BE */  sb        $v0, 0xbe($s0)
/* 7A730 800E1280 A200000F */  sb        $zero, 0xf($s0)
.L800E1284:
/* 7A734 800E1284 8E020004 */  lw        $v0, 4($s0)
/* 7A738 800E1288 30422000 */  andi      $v0, $v0, 0x2000
/* 7A73C 800E128C 14400012 */  bnez      $v0, .L800E12D8
/* 7A740 800E1290 3C030002 */   lui      $v1, 2
/* 7A744 800E1294 8FA20038 */  lw        $v0, 0x38($sp)
/* 7A748 800E1298 AE300008 */  sw        $s0, 8($s1)
/* 7A74C 800E129C 00021023 */  negu      $v0, $v0
/* 7A750 800E12A0 AE220004 */  sw        $v0, 4($s1)
/* 7A754 800E12A4 820200BE */  lb        $v0, 0xbe($s0)
/* 7A758 800E12A8 3C04800E */  lui       $a0, %hi(appendGfx_player_spin)
/* 7A75C 800E12AC 24841704 */  addiu     $a0, $a0, %lo(appendGfx_player_spin)
/* 7A760 800E12B0 AE220000 */  sw        $v0, ($s1)
/* 7A764 800E12B4 8E020000 */  lw        $v0, ($s0)
/* 7A768 800E12B8 00431024 */  and       $v0, $v0, $v1
/* 7A76C 800E12BC 54400004 */  bnel      $v0, $zero, .L800E12D0
/* 7A770 800E12C0 AE24000C */   sw       $a0, 0xc($s1)
/* 7A774 800E12C4 3C04800E */  lui       $a0, %hi(appendGfx_player)
/* 7A778 800E12C8 248412F4 */  addiu     $a0, $a0, %lo(appendGfx_player)
/* 7A77C 800E12CC AE24000C */  sw        $a0, 0xc($s1)
.L800E12D0:
/* 7A780 800E12D0 0C047644 */  jal       queue_render_task
/* 7A784 800E12D4 0220202D */   daddu    $a0, $s1, $zero
.L800E12D8:
/* 7A788 800E12D8 0C03C327 */  jal       func_800F0C9C
/* 7A78C 800E12DC 00000000 */   nop
.L800E12E0:
/* 7A790 800E12E0 8FBF0048 */  lw        $ra, 0x48($sp)
/* 7A794 800E12E4 8FB10044 */  lw        $s1, 0x44($sp)
/* 7A798 800E12E8 8FB00040 */  lw        $s0, 0x40($sp)
/* 7A79C 800E12EC 03E00008 */  jr        $ra
/* 7A7A0 800E12F0 27BD0050 */   addiu    $sp, $sp, 0x50
