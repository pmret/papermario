.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel filemenu_update_show_name_input_803C00
/* 803C00 80243380 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 803C04 80243384 AFB3001C */  sw        $s3, 0x1c($sp)
/* 803C08 80243388 0080982D */  daddu     $s3, $a0, $zero
/* 803C0C 8024338C AFBF0020 */  sw        $ra, 0x20($sp)
/* 803C10 80243390 AFB20018 */  sw        $s2, 0x18($sp)
/* 803C14 80243394 AFB10014 */  sw        $s1, 0x14($sp)
/* 803C18 80243398 AFB00010 */  sw        $s0, 0x10($sp)
/* 803C1C 8024339C 8E70000C */  lw        $s0, 0xc($s3)
/* 803C20 802433A0 8E050000 */  lw        $a1, ($s0)
/* 803C24 802433A4 0C0B1EAF */  jal       evt_get_variable
/* 803C28 802433A8 26100004 */   addiu    $s0, $s0, 4
/* 803C2C 802433AC 0260202D */  daddu     $a0, $s3, $zero
/* 803C30 802433B0 8E050000 */  lw        $a1, ($s0)
/* 803C34 802433B4 0C0B1EAF */  jal       evt_get_variable
/* 803C38 802433B8 0040902D */   daddu    $s2, $v0, $zero
/* 803C3C 802433BC 2404003C */  addiu     $a0, $zero, 0x3c
/* 803C40 802433C0 0C00AB39 */  jal       heap_malloc
/* 803C44 802433C4 0040882D */   daddu    $s1, $v0, $zero
/* 803C48 802433C8 0040802D */  daddu     $s0, $v0, $zero
/* 803C4C 802433CC 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 803C50 802433D0 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* 803C54 802433D4 AE120008 */  sw        $s2, 8($s0)
/* 803C58 802433D8 AE11000C */  sw        $s1, 0xc($s0)
/* 803C5C 802433DC 846200B0 */  lh        $v0, 0xb0($v1)
/* 803C60 802433E0 44820000 */  mtc1      $v0, $f0
/* 803C64 802433E4 00000000 */  nop
/* 803C68 802433E8 46800020 */  cvt.s.w   $f0, $f0
/* 803C6C 802433EC E6000034 */  swc1      $f0, 0x34($s0)
/* 803C70 802433F0 846200B2 */  lh        $v0, 0xb2($v1)
/* 803C74 802433F4 44820000 */  mtc1      $v0, $f0
/* 803C78 802433F8 00000000 */  nop
/* 803C7C 802433FC 46800020 */  cvt.s.w   $f0, $f0
/* 803C80 80243400 E6000038 */  swc1      $f0, 0x38($s0)
/* 803C84 80243404 C4600028 */  lwc1      $f0, 0x28($v1)
/* 803C88 80243408 E6000010 */  swc1      $f0, 0x10($s0)
/* 803C8C 8024340C C460002C */  lwc1      $f0, 0x2c($v1)
/* 803C90 80243410 E6000014 */  swc1      $f0, 0x14($s0)
/* 803C94 80243414 C4620030 */  lwc1      $f2, 0x30($v1)
/* 803C98 80243418 3C013F36 */  lui       $at, 0x3f36
/* 803C9C 8024341C 3421DB6E */  ori       $at, $at, 0xdb6e
/* 803CA0 80243420 44810000 */  mtc1      $at, $f0
/* 803CA4 80243424 24040001 */  addiu     $a0, $zero, 1
/* 803CA8 80243428 AE00001C */  sw        $zero, 0x1c($s0)
/* 803CAC 8024342C AE000020 */  sw        $zero, 0x20($s0)
/* 803CB0 80243430 AE000024 */  sw        $zero, 0x24($s0)
/* 803CB4 80243434 E6000028 */  swc1      $f0, 0x28($s0)
/* 803CB8 80243438 E600002C */  swc1      $f0, 0x2c($s0)
/* 803CBC 8024343C E6000030 */  swc1      $f0, 0x30($s0)
/* 803CC0 80243440 0C04E9C1 */  jal       func_8013A704
/* 803CC4 80243444 E6020018 */   swc1     $f2, 0x18($s0)
/* 803CC8 80243448 0000202D */  daddu     $a0, $zero, $zero
/* 803CCC 8024344C 3C058024 */  lui       $a1, %hi(func_80242FA4_803824)
/* 803CD0 80243450 24A52FA4 */  addiu     $a1, $a1, %lo(func_80242FA4_803824)
/* 803CD4 80243454 0C048C56 */  jal       create_generic_entity_world
/* 803CD8 80243458 AE020000 */   sw       $v0, ($s0)
/* 803CDC 8024345C 0260202D */  daddu     $a0, $s3, $zero
/* 803CE0 80243460 3C05FD05 */  lui       $a1, 0xfd05
/* 803CE4 80243464 34A50F8A */  ori       $a1, $a1, 0xf8a
/* 803CE8 80243468 0200302D */  daddu     $a2, $s0, $zero
/* 803CEC 8024346C 0C0B2026 */  jal       evt_set_variable
/* 803CF0 80243470 AE020004 */   sw       $v0, 4($s0)
/* 803CF4 80243474 8FBF0020 */  lw        $ra, 0x20($sp)
/* 803CF8 80243478 8FB3001C */  lw        $s3, 0x1c($sp)
/* 803CFC 8024347C 8FB20018 */  lw        $s2, 0x18($sp)
/* 803D00 80243480 8FB10014 */  lw        $s1, 0x14($sp)
/* 803D04 80243484 8FB00010 */  lw        $s0, 0x10($sp)
/* 803D08 80243488 24020002 */  addiu     $v0, $zero, 2
/* 803D0C 8024348C 03E00008 */  jr        $ra
/* 803D10 80243490 27BD0028 */   addiu    $sp, $sp, 0x28
