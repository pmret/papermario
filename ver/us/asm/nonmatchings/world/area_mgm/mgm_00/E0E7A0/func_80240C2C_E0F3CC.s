.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel mgm_00_UnkFunc15
/* E0F3CC 80240C2C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* E0F3D0 80240C30 AFB3003C */  sw        $s3, 0x3c($sp)
/* E0F3D4 80240C34 0080982D */  daddu     $s3, $a0, $zero
/* E0F3D8 80240C38 AFBF0040 */  sw        $ra, 0x40($sp)
/* E0F3DC 80240C3C AFB20038 */  sw        $s2, 0x38($sp)
/* E0F3E0 80240C40 AFB10034 */  sw        $s1, 0x34($sp)
/* E0F3E4 80240C44 AFB00030 */  sw        $s0, 0x30($sp)
/* E0F3E8 80240C48 8E720148 */  lw        $s2, 0x148($s3)
/* E0F3EC 80240C4C 00A0882D */  daddu     $s1, $a1, $zero
/* E0F3F0 80240C50 86440008 */  lh        $a0, 8($s2)
/* E0F3F4 80240C54 0C00EABB */  jal       get_npc_unsafe
/* E0F3F8 80240C58 00C0802D */   daddu    $s0, $a2, $zero
/* E0F3FC 80240C5C 0200202D */  daddu     $a0, $s0, $zero
/* E0F400 80240C60 0240282D */  daddu     $a1, $s2, $zero
/* E0F404 80240C64 24030001 */  addiu     $v1, $zero, 1
/* E0F408 80240C68 AFA30010 */  sw        $v1, 0x10($sp)
/* E0F40C 80240C6C 8E260024 */  lw        $a2, 0x24($s1)
/* E0F410 80240C70 8E270028 */  lw        $a3, 0x28($s1)
/* E0F414 80240C74 0C01242D */  jal       func_800490B4
/* E0F418 80240C78 0040802D */   daddu    $s0, $v0, $zero
/* E0F41C 80240C7C 1440001E */  bnez      $v0, .L80240CF8
/* E0F420 80240C80 0200202D */   daddu    $a0, $s0, $zero
/* E0F424 80240C84 24040002 */  addiu     $a0, $zero, 2
/* E0F428 80240C88 0200282D */  daddu     $a1, $s0, $zero
/* E0F42C 80240C8C 0000302D */  daddu     $a2, $zero, $zero
/* E0F430 80240C90 860300A8 */  lh        $v1, 0xa8($s0)
/* E0F434 80240C94 3C013F80 */  lui       $at, 0x3f80
/* E0F438 80240C98 44810000 */  mtc1      $at, $f0
/* E0F43C 80240C9C 3C014000 */  lui       $at, 0x4000
/* E0F440 80240CA0 44811000 */  mtc1      $at, $f2
/* E0F444 80240CA4 3C01C1A0 */  lui       $at, 0xc1a0
/* E0F448 80240CA8 44812000 */  mtc1      $at, $f4
/* E0F44C 80240CAC 2402000F */  addiu     $v0, $zero, 0xf
/* E0F450 80240CB0 AFA2001C */  sw        $v0, 0x1c($sp)
/* E0F454 80240CB4 44833000 */  mtc1      $v1, $f6
/* E0F458 80240CB8 00000000 */  nop
/* E0F45C 80240CBC 468031A0 */  cvt.s.w   $f6, $f6
/* E0F460 80240CC0 44073000 */  mfc1      $a3, $f6
/* E0F464 80240CC4 27A20028 */  addiu     $v0, $sp, 0x28
/* E0F468 80240CC8 AFA20020 */  sw        $v0, 0x20($sp)
/* E0F46C 80240CCC E7A00010 */  swc1      $f0, 0x10($sp)
/* E0F470 80240CD0 E7A20014 */  swc1      $f2, 0x14($sp)
/* E0F474 80240CD4 0C01BFA4 */  jal       fx_emote
/* E0F478 80240CD8 E7A40018 */   swc1     $f4, 0x18($sp)
/* E0F47C 80240CDC 8E4200CC */  lw        $v0, 0xcc($s2)
/* E0F480 80240CE0 8C430000 */  lw        $v1, ($v0)
/* E0F484 80240CE4 24020019 */  addiu     $v0, $zero, 0x19
/* E0F488 80240CE8 A602008E */  sh        $v0, 0x8e($s0)
/* E0F48C 80240CEC 2402000E */  addiu     $v0, $zero, 0xe
/* E0F490 80240CF0 0809034B */  j         .L80240D2C
/* E0F494 80240CF4 AE030028 */   sw       $v1, 0x28($s0)
.L80240CF8:
/* E0F498 80240CF8 0C00F598 */  jal       func_8003D660
/* E0F49C 80240CFC 24050001 */   addiu    $a1, $zero, 1
/* E0F4A0 80240D00 8E050018 */  lw        $a1, 0x18($s0)
/* E0F4A4 80240D04 8E06000C */  lw        $a2, 0xc($s0)
/* E0F4A8 80240D08 0C00EA95 */  jal       npc_move_heading
/* E0F4AC 80240D0C 0200202D */   daddu    $a0, $s0, $zero
/* E0F4B0 80240D10 8602008E */  lh        $v0, 0x8e($s0)
/* E0F4B4 80240D14 9603008E */  lhu       $v1, 0x8e($s0)
/* E0F4B8 80240D18 18400003 */  blez      $v0, .L80240D28
/* E0F4BC 80240D1C 2462FFFF */   addiu    $v0, $v1, -1
/* E0F4C0 80240D20 0809034C */  j         .L80240D30
/* E0F4C4 80240D24 A602008E */   sh       $v0, 0x8e($s0)
.L80240D28:
/* E0F4C8 80240D28 2402000C */  addiu     $v0, $zero, 0xc
.L80240D2C:
/* E0F4CC 80240D2C AE620070 */  sw        $v0, 0x70($s3)
.L80240D30:
/* E0F4D0 80240D30 8FBF0040 */  lw        $ra, 0x40($sp)
/* E0F4D4 80240D34 8FB3003C */  lw        $s3, 0x3c($sp)
/* E0F4D8 80240D38 8FB20038 */  lw        $s2, 0x38($sp)
/* E0F4DC 80240D3C 8FB10034 */  lw        $s1, 0x34($sp)
/* E0F4E0 80240D40 8FB00030 */  lw        $s0, 0x30($sp)
/* E0F4E4 80240D44 03E00008 */  jr        $ra
/* E0F4E8 80240D48 27BD0048 */   addiu    $sp, $sp, 0x48
