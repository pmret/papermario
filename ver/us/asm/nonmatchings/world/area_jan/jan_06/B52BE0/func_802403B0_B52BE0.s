.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403B0_B52BE0
/* B52BE0 802403B0 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* B52BE4 802403B4 AFB10034 */  sw        $s1, 0x34($sp)
/* B52BE8 802403B8 0080882D */  daddu     $s1, $a0, $zero
/* B52BEC 802403BC AFBF0038 */  sw        $ra, 0x38($sp)
/* B52BF0 802403C0 AFB00030 */  sw        $s0, 0x30($sp)
/* B52BF4 802403C4 10A00016 */  beqz      $a1, .L80240420
/* B52BF8 802403C8 8E30000C */   lw       $s0, 0xc($s1)
/* B52BFC 802403CC 8E050000 */  lw        $a1, ($s0)
/* B52C00 802403D0 0C0B1EAF */  jal       get_variable
/* B52C04 802403D4 26100004 */   addiu    $s0, $s0, 4
/* B52C08 802403D8 8E030000 */  lw        $v1, ($s0)
/* B52C0C 802403DC 0040202D */  daddu     $a0, $v0, $zero
/* B52C10 802403E0 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B52C14 802403E4 AE23007C */   sw       $v1, 0x7c($s1)
/* B52C18 802403E8 0C046B4C */  jal       get_model_from_list_index
/* B52C1C 802403EC 0040202D */   daddu    $a0, $v0, $zero
/* B52C20 802403F0 0040802D */  daddu     $s0, $v0, $zero
/* B52C24 802403F4 0000202D */  daddu     $a0, $zero, $zero
/* B52C28 802403F8 AE300074 */  sw        $s0, 0x74($s1)
/* B52C2C 802403FC 8E050098 */  lw        $a1, 0x98($s0)
/* B52C30 80240400 8E0700A0 */  lw        $a3, 0xa0($s0)
/* B52C34 80240404 0C044898 */  jal       create_shadow_type
/* B52C38 80240408 0000302D */   daddu    $a2, $zero, $zero
/* B52C3C 8024040C 0220202D */  daddu     $a0, $s1, $zero
/* B52C40 80240410 8E25007C */  lw        $a1, 0x7c($s1)
/* B52C44 80240414 0000302D */  daddu     $a2, $zero, $zero
/* B52C48 80240418 0C0B2026 */  jal       set_variable
/* B52C4C 8024041C AE220078 */   sw       $v0, 0x78($s1)
.L80240420:
/* B52C50 80240420 8E25007C */  lw        $a1, 0x7c($s1)
/* B52C54 80240424 0C0B1EAF */  jal       get_variable
/* B52C58 80240428 0220202D */   daddu    $a0, $s1, $zero
/* B52C5C 8024042C 1440002A */  bnez      $v0, .L802404D8
/* B52C60 80240430 00000000 */   nop
/* B52C64 80240434 8E240078 */  lw        $a0, 0x78($s1)
/* B52C68 80240438 0C044181 */  jal       get_shadow_by_index
/* B52C6C 8024043C 8E300074 */   lw       $s0, 0x74($s1)
/* B52C70 80240440 27A40018 */  addiu     $a0, $sp, 0x18
/* B52C74 80240444 27A5001C */  addiu     $a1, $sp, 0x1c
/* B52C78 80240448 27A60020 */  addiu     $a2, $sp, 0x20
/* B52C7C 8024044C 27A70024 */  addiu     $a3, $sp, 0x24
/* B52C80 80240450 27A30028 */  addiu     $v1, $sp, 0x28
/* B52C84 80240454 C6000098 */  lwc1      $f0, 0x98($s0)
/* B52C88 80240458 C602009C */  lwc1      $f2, 0x9c($s0)
/* B52C8C 8024045C C60400A0 */  lwc1      $f4, 0xa0($s0)
/* B52C90 80240460 0040802D */  daddu     $s0, $v0, $zero
/* B52C94 80240464 E7A00018 */  swc1      $f0, 0x18($sp)
/* B52C98 80240468 E7A2001C */  swc1      $f2, 0x1c($sp)
/* B52C9C 8024046C E7A40020 */  swc1      $f4, 0x20($sp)
/* B52CA0 80240470 AFA30010 */  sw        $v1, 0x10($sp)
/* B52CA4 80240474 27A3002C */  addiu     $v1, $sp, 0x2c
/* B52CA8 80240478 0C04497A */  jal       func_801125E8
/* B52CAC 8024047C AFA30014 */   sw       $v1, 0x14($sp)
/* B52CB0 80240480 8FA5002C */  lw        $a1, 0x2c($sp)
/* B52CB4 80240484 0C044A17 */  jal       set_standard_shadow_scale
/* B52CB8 80240488 0200202D */   daddu    $a0, $s0, $zero
/* B52CBC 8024048C C7A00018 */  lwc1      $f0, 0x18($sp)
/* B52CC0 80240490 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* B52CC4 80240494 C7A60020 */  lwc1      $f6, 0x20($sp)
/* B52CC8 80240498 C7A80024 */  lwc1      $f8, 0x24($sp)
/* B52CCC 8024049C C604001C */  lwc1      $f4, 0x1c($s0)
/* B52CD0 802404A0 0000102D */  daddu     $v0, $zero, $zero
/* B52CD4 802404A4 AE00002C */  sw        $zero, 0x2c($s0)
/* B52CD8 802404A8 E6000010 */  swc1      $f0, 0x10($s0)
/* B52CDC 802404AC C6000024 */  lwc1      $f0, 0x24($s0)
/* B52CE0 802404B0 46042100 */  add.s     $f4, $f4, $f4
/* B52CE4 802404B4 E6020014 */  swc1      $f2, 0x14($s0)
/* B52CE8 802404B8 E6060018 */  swc1      $f6, 0x18($s0)
/* B52CEC 802404BC E6080028 */  swc1      $f8, 0x28($s0)
/* B52CF0 802404C0 C7A20028 */  lwc1      $f2, 0x28($sp)
/* B52CF4 802404C4 46000000 */  add.s     $f0, $f0, $f0
/* B52CF8 802404C8 E6020030 */  swc1      $f2, 0x30($s0)
/* B52CFC 802404CC E604001C */  swc1      $f4, 0x1c($s0)
/* B52D00 802404D0 0809013A */  j         .L802404E8
/* B52D04 802404D4 E6000024 */   swc1     $f0, 0x24($s0)
.L802404D8:
/* B52D08 802404D8 8E240078 */  lw        $a0, 0x78($s1)
/* B52D0C 802404DC 0C0448CA */  jal       func_80112328
/* B52D10 802404E0 00000000 */   nop
/* B52D14 802404E4 24020002 */  addiu     $v0, $zero, 2
.L802404E8:
/* B52D18 802404E8 8FBF0038 */  lw        $ra, 0x38($sp)
/* B52D1C 802404EC 8FB10034 */  lw        $s1, 0x34($sp)
/* B52D20 802404F0 8FB00030 */  lw        $s0, 0x30($sp)
/* B52D24 802404F4 03E00008 */  jr        $ra
/* B52D28 802404F8 27BD0040 */   addiu    $sp, $sp, 0x40
/* B52D2C 802404FC 00000000 */  nop
