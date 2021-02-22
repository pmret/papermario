.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A15B0_78A410
/* 78A410 802A15B0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 78A414 802A15B4 AFB10014 */  sw        $s1, 0x14($sp)
/* 78A418 802A15B8 0080882D */  daddu     $s1, $a0, $zero
/* 78A41C 802A15BC 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 78A420 802A15C0 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* 78A424 802A15C4 AFB00010 */  sw        $s0, 0x10($sp)
/* 78A428 802A15C8 0040802D */  daddu     $s0, $v0, $zero
/* 78A42C 802A15CC AFBF0018 */  sw        $ra, 0x18($sp)
/* 78A430 802A15D0 AE200084 */  sw        $zero, 0x84($s1)
/* 78A434 802A15D4 8202028E */  lb        $v0, 0x28e($s0)
/* 78A438 802A15D8 86030290 */  lh        $v1, 0x290($s0)
/* 78A43C 802A15DC 00021200 */  sll       $v0, $v0, 8
/* 78A440 802A15E0 0062182A */  slt       $v1, $v1, $v0
/* 78A444 802A15E4 10600008 */  beqz      $v1, .L802A1608
/* 78A448 802A15E8 24020001 */   addiu    $v0, $zero, 1
/* 78A44C 802A15EC 0C03A87D */  jal       add_SP
/* 78A450 802A15F0 24040080 */   addiu    $a0, $zero, 0x80
/* 78A454 802A15F4 8202028E */  lb        $v0, 0x28e($s0)
/* 78A458 802A15F8 86030290 */  lh        $v1, 0x290($s0)
/* 78A45C 802A15FC 00021200 */  sll       $v0, $v0, 8
/* 78A460 802A1600 14620003 */  bne       $v1, $v0, .L802A1610
/* 78A464 802A1604 24020002 */   addiu    $v0, $zero, 2
.L802A1608:
/* 78A468 802A1608 AE220084 */  sw        $v0, 0x84($s1)
/* 78A46C 802A160C 24020002 */  addiu     $v0, $zero, 2
.L802A1610:
/* 78A470 802A1610 8FBF0018 */  lw        $ra, 0x18($sp)
/* 78A474 802A1614 8FB10014 */  lw        $s1, 0x14($sp)
/* 78A478 802A1618 8FB00010 */  lw        $s0, 0x10($sp)
/* 78A47C 802A161C 03E00008 */  jr        $ra
