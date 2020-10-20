.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802433B4
/* A1E4B4 802433B4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A1E4B8 802433B8 AFB10014 */  sw        $s1, 0x14($sp)
/* A1E4BC 802433BC 0080882D */  daddu     $s1, $a0, $zero
/* A1E4C0 802433C0 AFB00010 */  sw        $s0, 0x10($sp)
/* A1E4C4 802433C4 00A0802D */  daddu     $s0, $a1, $zero
/* A1E4C8 802433C8 AFBF001C */  sw        $ra, 0x1c($sp)
/* A1E4CC 802433CC AFB20018 */  sw        $s2, 0x18($sp)
/* A1E4D0 802433D0 F7B40020 */  sdc1      $f20, 0x20($sp)
/* A1E4D4 802433D4 0C00EABB */  jal       get_npc_unsafe
/* A1E4D8 802433D8 2404FFFC */   addiu    $a0, $zero, -4
/* A1E4DC 802433DC 12000017 */  beqz      $s0, .L8024343C
/* A1E4E0 802433E0 0040902D */   daddu    $s2, $v0, $zero
/* A1E4E4 802433E4 0220202D */  daddu     $a0, $s1, $zero
/* A1E4E8 802433E8 3C05FE36 */  lui       $a1, 0xfe36
/* A1E4EC 802433EC 0C0B210B */  jal       get_float_variable
/* A1E4F0 802433F0 34A53C80 */   ori      $a1, $a1, 0x3c80
/* A1E4F4 802433F4 0220202D */  daddu     $a0, $s1, $zero
/* A1E4F8 802433F8 3C05FE36 */  lui       $a1, 0xfe36
/* A1E4FC 802433FC 3C014270 */  lui       $at, 0x4270
/* A1E500 80243400 4481A000 */  mtc1      $at, $f20
/* A1E504 80243404 34A53C85 */  ori       $a1, $a1, 0x3c85
/* A1E508 80243408 46140003 */  div.s     $f0, $f0, $f20
/* A1E50C 8024340C 0C0B210B */  jal       get_float_variable
/* A1E510 80243410 E6200074 */   swc1     $f0, 0x74($s1)
/* A1E514 80243414 0220202D */  daddu     $a0, $s1, $zero
/* A1E518 80243418 3C05FE36 */  lui       $a1, 0xfe36
/* A1E51C 8024341C 34A53C81 */  ori       $a1, $a1, 0x3c81
/* A1E520 80243420 46140003 */  div.s     $f0, $f0, $f20
/* A1E524 80243424 0C0B210B */  jal       get_float_variable
/* A1E528 80243428 E6200078 */   swc1     $f0, 0x78($s1)
/* A1E52C 8024342C 46140003 */  div.s     $f0, $f0, $f20
/* A1E530 80243430 2402003C */  addiu     $v0, $zero, 0x3c
/* A1E534 80243434 E620007C */  swc1      $f0, 0x7c($s1)
/* A1E538 80243438 AE220070 */  sw        $v0, 0x70($s1)
.L8024343C:
/* A1E53C 8024343C C6400038 */  lwc1      $f0, 0x38($s2)
/* A1E540 80243440 C6220074 */  lwc1      $f2, 0x74($s1)
/* A1E544 80243444 46020000 */  add.s     $f0, $f0, $f2
/* A1E548 80243448 E6400038 */  swc1      $f0, 0x38($s2)
/* A1E54C 8024344C C640003C */  lwc1      $f0, 0x3c($s2)
/* A1E550 80243450 C6220078 */  lwc1      $f2, 0x78($s1)
/* A1E554 80243454 46020000 */  add.s     $f0, $f0, $f2
/* A1E558 80243458 E640003C */  swc1      $f0, 0x3c($s2)
/* A1E55C 8024345C C6400040 */  lwc1      $f0, 0x40($s2)
/* A1E560 80243460 C622007C */  lwc1      $f2, 0x7c($s1)
/* A1E564 80243464 46020000 */  add.s     $f0, $f0, $f2
/* A1E568 80243468 E6400040 */  swc1      $f0, 0x40($s2)
/* A1E56C 8024346C 8E230070 */  lw        $v1, 0x70($s1)
/* A1E570 80243470 2463FFFF */  addiu     $v1, $v1, -1
/* A1E574 80243474 2C620001 */  sltiu     $v0, $v1, 1
/* A1E578 80243478 AE230070 */  sw        $v1, 0x70($s1)
/* A1E57C 8024347C 8FBF001C */  lw        $ra, 0x1c($sp)
/* A1E580 80243480 8FB20018 */  lw        $s2, 0x18($sp)
/* A1E584 80243484 8FB10014 */  lw        $s1, 0x14($sp)
/* A1E588 80243488 8FB00010 */  lw        $s0, 0x10($sp)
/* A1E58C 8024348C D7B40020 */  ldc1      $f20, 0x20($sp)
/* A1E590 80243490 00021040 */  sll       $v0, $v0, 1
/* A1E594 80243494 03E00008 */  jr        $ra
/* A1E598 80243498 27BD0028 */   addiu    $sp, $sp, 0x28
