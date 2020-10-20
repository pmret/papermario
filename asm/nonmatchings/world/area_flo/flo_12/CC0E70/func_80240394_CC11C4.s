.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240394_CC11C4
/* CC11C4 80240394 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CC11C8 80240398 AFB10014 */  sw        $s1, 0x14($sp)
/* CC11CC 8024039C 0080882D */  daddu     $s1, $a0, $zero
/* CC11D0 802403A0 AFBF0018 */  sw        $ra, 0x18($sp)
/* CC11D4 802403A4 AFB00010 */  sw        $s0, 0x10($sp)
/* CC11D8 802403A8 8E30000C */  lw        $s0, 0xc($s1)
/* CC11DC 802403AC 8E050000 */  lw        $a1, ($s0)
/* CC11E0 802403B0 0C0B1EAF */  jal       get_variable
/* CC11E4 802403B4 26100004 */   addiu    $s0, $s0, 4
/* CC11E8 802403B8 0C00EAD2 */  jal       get_npc_safe
/* CC11EC 802403BC 0040202D */   daddu    $a0, $v0, $zero
/* CC11F0 802403C0 10400005 */  beqz      $v0, .L802403D8
/* CC11F4 802403C4 00000000 */   nop      
/* CC11F8 802403C8 8E050000 */  lw        $a1, ($s0)
/* CC11FC 802403CC 844600A8 */  lh        $a2, 0xa8($v0)
/* CC1200 802403D0 0C0B2026 */  jal       set_variable
/* CC1204 802403D4 0220202D */   daddu    $a0, $s1, $zero
.L802403D8:
/* CC1208 802403D8 8FBF0018 */  lw        $ra, 0x18($sp)
/* CC120C 802403DC 8FB10014 */  lw        $s1, 0x14($sp)
/* CC1210 802403E0 8FB00010 */  lw        $s0, 0x10($sp)
/* CC1214 802403E4 24020002 */  addiu     $v0, $zero, 2
/* CC1218 802403E8 03E00008 */  jr        $ra
/* CC121C 802403EC 27BD0020 */   addiu    $sp, $sp, 0x20
