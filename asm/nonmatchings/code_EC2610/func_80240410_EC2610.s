.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240410_EC2610
/* EC2610 80240410 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* EC2614 80240414 F7B40018 */  sdc1      $f20, 0x18($sp)
/* EC2618 80240418 4485A000 */  mtc1      $a1, $f20
/* EC261C 8024041C F7B60020 */  sdc1      $f22, 0x20($sp)
/* EC2620 80240420 4486B000 */  mtc1      $a2, $f22
/* EC2624 80240424 AFB00010 */  sw        $s0, 0x10($sp)
/* EC2628 80240428 F7B80028 */  sdc1      $f24, 0x28($sp)
/* EC262C 8024042C 4487C000 */  mtc1      $a3, $f24
/* EC2630 80240430 AFBF0014 */  sw        $ra, 0x14($sp)
/* EC2634 80240434 0C01B198 */  jal       __osGetCause
/* EC2638 80240438 0080802D */   daddu    $s0, $a0, $zero
/* EC263C 8024043C 4616A582 */  mul.s     $f22, $f20, $f22
/* EC2640 80240440 00000000 */  nop
/* EC2644 80240444 4618A502 */  mul.s     $f20, $f20, $f24
/* EC2648 80240448 00000000 */  nop
/* EC264C 8024044C 3C013F80 */  lui       $at, 0x3f80
/* EC2650 80240450 44810000 */  mtc1      $at, $f0
/* EC2654 80240454 00000000 */  nop
/* EC2658 80240458 E6000014 */  swc1      $f0, 0x14($s0)
/* EC265C 8024045C E6160010 */  swc1      $f22, 0x10($s0)
/* EC2660 80240460 E6140018 */  swc1      $f20, 0x18($s0)
/* EC2664 80240464 8FBF0014 */  lw        $ra, 0x14($sp)
/* EC2668 80240468 8FB00010 */  lw        $s0, 0x10($sp)
/* EC266C 8024046C D7B80028 */  ldc1      $f24, 0x28($sp)
/* EC2670 80240470 D7B60020 */  ldc1      $f22, 0x20($sp)
/* EC2674 80240474 D7B40018 */  ldc1      $f20, 0x18($sp)
/* EC2678 80240478 03E00008 */  jr        $ra
/* EC267C 8024047C 27BD0030 */   addiu    $sp, $sp, 0x30
