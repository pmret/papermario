.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802429C0_EA32C0
/* EA32C0 802429C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EA32C4 802429C4 AFBF0010 */  sw        $ra, 0x10($sp)
/* EA32C8 802429C8 10A00003 */  beqz      $a1, .L802429D8
/* EA32CC 802429CC 8C86000C */   lw       $a2, 0xc($a0)
/* EA32D0 802429D0 3C018024 */  lui       $at, %hi(D_802441B8)
/* EA32D4 802429D4 AC2041B8 */  sw        $zero, %lo(D_802441B8)($at)
.L802429D8:
/* EA32D8 802429D8 3C038024 */  lui       $v1, %hi(D_802441B8)
/* EA32DC 802429DC 246341B8 */  addiu     $v1, $v1, %lo(D_802441B8)
/* EA32E0 802429E0 8C620000 */  lw        $v0, ($v1)
/* EA32E4 802429E4 54400003 */  bnel      $v0, $zero, .L802429F4
/* EA32E8 802429E8 AC600000 */   sw       $zero, ($v1)
/* EA32EC 802429EC 08090A82 */  j         .L80242A08
/* EA32F0 802429F0 0000102D */   daddu    $v0, $zero, $zero
.L802429F4:
/* EA32F4 802429F4 8CC50000 */  lw        $a1, ($a2)
/* EA32F8 802429F8 3C068024 */  lui       $a2, %hi(D_802441BC)
/* EA32FC 802429FC 0C0B551A */  jal       func_802D5468
/* EA3300 80242A00 8CC641BC */   lw       $a2, %lo(D_802441BC)($a2)
/* EA3304 80242A04 24020002 */  addiu     $v0, $zero, 2
.L80242A08:
/* EA3308 80242A08 8FBF0010 */  lw        $ra, 0x10($sp)
/* EA330C 80242A0C 03E00008 */  jr        $ra
/* EA3310 80242A10 27BD0018 */   addiu    $sp, $sp, 0x18
