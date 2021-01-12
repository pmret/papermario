.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024037C_EA0C7C
/* EA0C7C 8024037C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EA0C80 80240380 AFB10014 */  sw        $s1, 0x14($sp)
/* EA0C84 80240384 0080882D */  daddu     $s1, $a0, $zero
/* EA0C88 80240388 AFBF0018 */  sw        $ra, 0x18($sp)
/* EA0C8C 8024038C AFB00010 */  sw        $s0, 0x10($sp)
/* EA0C90 80240390 8E300148 */  lw        $s0, 0x148($s1)
/* EA0C94 80240394 0C00F92F */  jal       func_8003E4BC
/* EA0C98 80240398 86040008 */   lh       $a0, 8($s0)
/* EA0C9C 8024039C 0040202D */  daddu     $a0, $v0, $zero
/* EA0CA0 802403A0 9482008E */  lhu       $v0, 0x8e($a0)
/* EA0CA4 802403A4 2442FFFF */  addiu     $v0, $v0, -1
/* EA0CA8 802403A8 A482008E */  sh        $v0, 0x8e($a0)
/* EA0CAC 802403AC 00021400 */  sll       $v0, $v0, 0x10
/* EA0CB0 802403B0 1C400009 */  bgtz      $v0, .L802403D8
/* EA0CB4 802403B4 24020003 */   addiu    $v0, $zero, 3
/* EA0CB8 802403B8 96030076 */  lhu       $v1, 0x76($s0)
/* EA0CBC 802403BC AE02006C */  sw        $v0, 0x6c($s0)
/* EA0CC0 802403C0 A483008E */  sh        $v1, 0x8e($a0)
/* EA0CC4 802403C4 8E0200CC */  lw        $v0, 0xcc($s0)
/* EA0CC8 802403C8 8C420024 */  lw        $v0, 0x24($v0)
/* EA0CCC 802403CC AC820028 */  sw        $v0, 0x28($a0)
/* EA0CD0 802403D0 24020020 */  addiu     $v0, $zero, 0x20
/* EA0CD4 802403D4 AE220070 */  sw        $v0, 0x70($s1)
.L802403D8:
/* EA0CD8 802403D8 8FBF0018 */  lw        $ra, 0x18($sp)
/* EA0CDC 802403DC 8FB10014 */  lw        $s1, 0x14($sp)
/* EA0CE0 802403E0 8FB00010 */  lw        $s0, 0x10($sp)
/* EA0CE4 802403E4 03E00008 */  jr        $ra
/* EA0CE8 802403E8 27BD0020 */   addiu    $sp, $sp, 0x20
