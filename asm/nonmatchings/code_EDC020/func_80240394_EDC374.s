.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240394_EDC374
/* EDC374 80240394 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EDC378 80240398 AFB10014 */  sw        $s1, 0x14($sp)
/* EDC37C 8024039C 0080882D */  daddu     $s1, $a0, $zero
/* EDC380 802403A0 AFBF0018 */  sw        $ra, 0x18($sp)
/* EDC384 802403A4 AFB00010 */  sw        $s0, 0x10($sp)
/* EDC388 802403A8 8E30000C */  lw        $s0, 0xc($s1)
/* EDC38C 802403AC 8E050000 */  lw        $a1, ($s0)
/* EDC390 802403B0 0C0B53A3 */  jal       func_802D4E8C
/* EDC394 802403B4 26100004 */   addiu    $s0, $s0, 4
/* EDC398 802403B8 0C00F94D */  jal       func_8003E534
/* EDC39C 802403BC 0040202D */   daddu    $a0, $v0, $zero
/* EDC3A0 802403C0 10400005 */  beqz      $v0, .L802403D8
/* EDC3A4 802403C4 00000000 */   nop      
/* EDC3A8 802403C8 8E050000 */  lw        $a1, ($s0)
/* EDC3AC 802403CC 844600A8 */  lh        $a2, 0xa8($v0)
/* EDC3B0 802403D0 0C0B551A */  jal       func_802D5468
/* EDC3B4 802403D4 0220202D */   daddu    $a0, $s1, $zero
.L802403D8:
/* EDC3B8 802403D8 8FBF0018 */  lw        $ra, 0x18($sp)
/* EDC3BC 802403DC 8FB10014 */  lw        $s1, 0x14($sp)
/* EDC3C0 802403E0 8FB00010 */  lw        $s0, 0x10($sp)
/* EDC3C4 802403E4 24020002 */  addiu     $v0, $zero, 2
/* EDC3C8 802403E8 03E00008 */  jr        $ra
/* EDC3CC 802403EC 27BD0020 */   addiu    $sp, $sp, 0x20
