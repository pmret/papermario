.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403A0_D36690
/* D36690 802403A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D36694 802403A4 AFB00010 */  sw        $s0, 0x10($sp)
/* D36698 802403A8 0080802D */  daddu     $s0, $a0, $zero
/* D3669C 802403AC AFBF0014 */  sw        $ra, 0x14($sp)
/* D366A0 802403B0 0C00AB39 */  jal       heap_malloc
/* D366A4 802403B4 24040170 */   addiu    $a0, $zero, 0x170
/* D366A8 802403B8 2405005A */  addiu     $a1, $zero, 0x5a
/* D366AC 802403BC 24440168 */  addiu     $a0, $v0, 0x168
/* D366B0 802403C0 240300DA */  addiu     $v1, $zero, 0xda
/* D366B4 802403C4 AE020084 */  sw        $v0, 0x84($s0)
.L802403C8:
/* D366B8 802403C8 AC830000 */  sw        $v1, ($a0)
/* D366BC 802403CC 2484FFFC */  addiu     $a0, $a0, -4
/* D366C0 802403D0 24A5FFFF */  addiu     $a1, $a1, -1
/* D366C4 802403D4 04A1FFFC */  bgez      $a1, .L802403C8
/* D366C8 802403D8 2463FFFF */   addiu    $v1, $v1, -1
/* D366CC 802403DC AC40016C */  sw        $zero, 0x16c($v0)
/* D366D0 802403E0 8FBF0014 */  lw        $ra, 0x14($sp)
/* D366D4 802403E4 8FB00010 */  lw        $s0, 0x10($sp)
/* D366D8 802403E8 24020002 */  addiu     $v0, $zero, 2
/* D366DC 802403EC 03E00008 */  jr        $ra
/* D366E0 802403F0 27BD0018 */   addiu    $sp, $sp, 0x18
/* D366E4 802403F4 00000000 */  nop       
/* D366E8 802403F8 00000000 */  nop       
/* D366EC 802403FC 00000000 */  nop       
