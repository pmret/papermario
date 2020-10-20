.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242BBC
/* BE636C 80242BBC 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BE6370 80242BC0 AFB3003C */  sw        $s3, 0x3c($sp)
/* BE6374 80242BC4 0080982D */  daddu     $s3, $a0, $zero
/* BE6378 80242BC8 AFBF0040 */  sw        $ra, 0x40($sp)
/* BE637C 80242BCC AFB20038 */  sw        $s2, 0x38($sp)
/* BE6380 80242BD0 AFB10034 */  sw        $s1, 0x34($sp)
/* BE6384 80242BD4 AFB00030 */  sw        $s0, 0x30($sp)
/* BE6388 80242BD8 8E720148 */  lw        $s2, 0x148($s3)
/* BE638C 80242BDC 0C00EABB */  jal       get_npc_unsafe
/* BE6390 80242BE0 86440008 */   lh       $a0, 8($s2)
/* BE6394 80242BE4 0040802D */  daddu     $s0, $v0, $zero
/* BE6398 80242BE8 0200202D */  daddu     $a0, $s0, $zero
/* BE639C 80242BEC 0C00F598 */  jal       func_8003D660
/* BE63A0 80242BF0 24050001 */   addiu    $a1, $zero, 1
/* BE63A4 80242BF4 8E050018 */  lw        $a1, 0x18($s0)
/* BE63A8 80242BF8 8E06000C */  lw        $a2, 0xc($s0)
/* BE63AC 80242BFC 0C00EA95 */  jal       npc_move_heading
/* BE63B0 80242C00 0200202D */   daddu    $a0, $s0, $zero
/* BE63B4 80242C04 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BE63B8 80242C08 C6000040 */  lwc1      $f0, 0x40($s0)
/* BE63BC 80242C0C C462001C */  lwc1      $f2, 0x1c($v1)
/* BE63C0 80242C10 468010A0 */  cvt.s.w   $f2, $f2
/* BE63C4 80242C14 C4640024 */  lwc1      $f4, 0x24($v1)
/* BE63C8 80242C18 46802120 */  cvt.s.w   $f4, $f4
/* BE63CC 80242C1C E7A00010 */  swc1      $f0, 0x10($sp)
/* BE63D0 80242C20 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BE63D4 80242C24 44051000 */  mfc1      $a1, $f2
/* BE63D8 80242C28 C4400028 */  lwc1      $f0, 0x28($v0)
/* BE63DC 80242C2C 46800020 */  cvt.s.w   $f0, $f0
/* BE63E0 80242C30 E7A00014 */  swc1      $f0, 0x14($sp)
/* BE63E4 80242C34 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BE63E8 80242C38 44062000 */  mfc1      $a2, $f4
/* BE63EC 80242C3C C440002C */  lwc1      $f0, 0x2c($v0)
/* BE63F0 80242C40 46800020 */  cvt.s.w   $f0, $f0
/* BE63F4 80242C44 E7A00018 */  swc1      $f0, 0x18($sp)
/* BE63F8 80242C48 8C640030 */  lw        $a0, 0x30($v1)
/* BE63FC 80242C4C 0C0123F5 */  jal       is_point_within_region
/* BE6400 80242C50 8E070038 */   lw       $a3, 0x38($s0)
/* BE6404 80242C54 C6000038 */  lwc1      $f0, 0x38($s0)
/* BE6408 80242C58 C602003C */  lwc1      $f2, 0x3c($s0)
/* BE640C 80242C5C C6040040 */  lwc1      $f4, 0x40($s0)
/* BE6410 80242C60 3C013F80 */  lui       $at, 0x3f80
/* BE6414 80242C64 44813000 */  mtc1      $at, $f6
/* BE6418 80242C68 E7A00020 */  swc1      $f0, 0x20($sp)
/* BE641C 80242C6C E7A20024 */  swc1      $f2, 0x24($sp)
/* BE6420 80242C70 E7A40028 */  swc1      $f4, 0x28($sp)
/* BE6424 80242C74 E7A60010 */  swc1      $f6, 0x10($sp)
/* BE6428 80242C78 C600000C */  lwc1      $f0, 0xc($s0)
/* BE642C 80242C7C 0002882B */  sltu      $s1, $zero, $v0
/* BE6430 80242C80 E7A00014 */  swc1      $f0, 0x14($sp)
/* BE6434 80242C84 860200A8 */  lh        $v0, 0xa8($s0)
/* BE6438 80242C88 27A50020 */  addiu     $a1, $sp, 0x20
/* BE643C 80242C8C 44820000 */  mtc1      $v0, $f0
/* BE6440 80242C90 00000000 */  nop       
/* BE6444 80242C94 46800020 */  cvt.s.w   $f0, $f0
/* BE6448 80242C98 E7A00018 */  swc1      $f0, 0x18($sp)
/* BE644C 80242C9C 860200A6 */  lh        $v0, 0xa6($s0)
/* BE6450 80242CA0 27A60024 */  addiu     $a2, $sp, 0x24
/* BE6454 80242CA4 44820000 */  mtc1      $v0, $f0
/* BE6458 80242CA8 00000000 */  nop       
/* BE645C 80242CAC 46800020 */  cvt.s.w   $f0, $f0
/* BE6460 80242CB0 E7A0001C */  swc1      $f0, 0x1c($sp)
/* BE6464 80242CB4 8E040080 */  lw        $a0, 0x80($s0)
/* BE6468 80242CB8 0C037711 */  jal       func_800DDC44
/* BE646C 80242CBC 27A70028 */   addiu    $a3, $sp, 0x28
/* BE6470 80242CC0 54400001 */  bnel      $v0, $zero, .L80242CC8
/* BE6474 80242CC4 24110001 */   addiu    $s1, $zero, 1
.L80242CC8:
/* BE6478 80242CC8 9602008E */  lhu       $v0, 0x8e($s0)
/* BE647C 80242CCC 2442FFFF */  addiu     $v0, $v0, -1
/* BE6480 80242CD0 A602008E */  sh        $v0, 0x8e($s0)
/* BE6484 80242CD4 00021400 */  sll       $v0, $v0, 0x10
/* BE6488 80242CD8 58400001 */  blezl     $v0, .L80242CE0
/* BE648C 80242CDC 24110001 */   addiu    $s1, $zero, 1
.L80242CE0:
/* BE6490 80242CE0 12200003 */  beqz      $s1, .L80242CF0
/* BE6494 80242CE4 24020004 */   addiu    $v0, $zero, 4
/* BE6498 80242CE8 AE620070 */  sw        $v0, 0x70($s3)
/* BE649C 80242CEC A2400007 */  sb        $zero, 7($s2)
.L80242CF0:
/* BE64A0 80242CF0 8FBF0040 */  lw        $ra, 0x40($sp)
/* BE64A4 80242CF4 8FB3003C */  lw        $s3, 0x3c($sp)
/* BE64A8 80242CF8 8FB20038 */  lw        $s2, 0x38($sp)
/* BE64AC 80242CFC 8FB10034 */  lw        $s1, 0x34($sp)
/* BE64B0 80242D00 8FB00030 */  lw        $s0, 0x30($sp)
/* BE64B4 80242D04 03E00008 */  jr        $ra
/* BE64B8 80242D08 27BD0048 */   addiu    $sp, $sp, 0x48
