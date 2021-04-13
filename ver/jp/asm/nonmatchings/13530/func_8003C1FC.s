.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003C1FC
/* 175FC 8003C1FC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 17600 8003C200 AFB00010 */  sw        $s0, 0x10($sp)
/* 17604 8003C204 0080802D */  daddu     $s0, $a0, $zero
/* 17608 8003C208 AFB10014 */  sw        $s1, 0x14($sp)
/* 1760C 8003C20C 00A0882D */  daddu     $s1, $a1, $zero
/* 17610 8003C210 02111021 */  addu      $v0, $s0, $s1
/* 17614 8003C214 AFBF0018 */  sw        $ra, 0x18($sp)
/* 17618 8003C218 8043032C */  lb        $v1, 0x32c($v0)
/* 1761C 8003C21C 2C620007 */  sltiu     $v0, $v1, 7
/* 17620 8003C220 10400027 */  beqz      $v0, .L8003C2C0
/* 17624 8003C224 00031080 */   sll      $v0, $v1, 2
/* 17628 8003C228 3C01800A */  lui       $at, %hi(D_800984E0)
/* 1762C 8003C22C 00220821 */  addu      $at, $at, $v0
/* 17630 8003C230 8C2284E0 */  lw        $v0, %lo(D_800984E0)($at)
/* 17634 8003C234 00400008 */  jr        $v0
/* 17638 8003C238 00000000 */   nop
/* 1763C 8003C23C 0200202D */  daddu     $a0, $s0, $zero
/* 17640 8003C240 0C00F0C8 */  jal       func_8003C320
/* 17644 8003C244 0220282D */   daddu    $a1, $s1, $zero
/* 17648 8003C248 0800F0B1 */  j         .L8003C2C4
/* 1764C 8003C24C 02111021 */   addu     $v0, $s0, $s1
/* 17650 8003C250 0200202D */  daddu     $a0, $s0, $zero
/* 17654 8003C254 0C00F113 */  jal       func_8003C44C
/* 17658 8003C258 0220282D */   daddu    $a1, $s1, $zero
/* 1765C 8003C25C 0800F0B1 */  j         .L8003C2C4
/* 17660 8003C260 02111021 */   addu     $v0, $s0, $s1
/* 17664 8003C264 0200202D */  daddu     $a0, $s0, $zero
/* 17668 8003C268 0C00F15B */  jal       func_8003C56C
/* 1766C 8003C26C 0220282D */   daddu    $a1, $s1, $zero
/* 17670 8003C270 0800F0B1 */  j         .L8003C2C4
/* 17674 8003C274 02111021 */   addu     $v0, $s0, $s1
/* 17678 8003C278 0200202D */  daddu     $a0, $s0, $zero
/* 1767C 8003C27C 0C00F191 */  jal       func_8003C644
/* 17680 8003C280 0220282D */   daddu    $a1, $s1, $zero
/* 17684 8003C284 0800F0B1 */  j         .L8003C2C4
/* 17688 8003C288 02111021 */   addu     $v0, $s0, $s1
/* 1768C 8003C28C 0200202D */  daddu     $a0, $s0, $zero
/* 17690 8003C290 0C00F1F8 */  jal       func_8003C7E0
/* 17694 8003C294 0220282D */   daddu    $a1, $s1, $zero
/* 17698 8003C298 0800F0B1 */  j         .L8003C2C4
/* 1769C 8003C29C 02111021 */   addu     $v0, $s0, $s1
/* 176A0 8003C2A0 0200202D */  daddu     $a0, $s0, $zero
/* 176A4 8003C2A4 0C00F253 */  jal       func_8003C94C
/* 176A8 8003C2A8 0220282D */   daddu    $a1, $s1, $zero
/* 176AC 8003C2AC 0800F0B1 */  j         .L8003C2C4
/* 176B0 8003C2B0 02111021 */   addu     $v0, $s0, $s1
/* 176B4 8003C2B4 0200202D */  daddu     $a0, $s0, $zero
/* 176B8 8003C2B8 0C00F318 */  jal       func_8003CC60
/* 176BC 8003C2BC 0220282D */   daddu    $a1, $s1, $zero
.L8003C2C0:
/* 176C0 8003C2C0 02111021 */  addu      $v0, $s0, $s1
.L8003C2C4:
/* 176C4 8003C2C4 A040032C */  sb        $zero, 0x32c($v0)
/* 176C8 8003C2C8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 176CC 8003C2CC 8FB10014 */  lw        $s1, 0x14($sp)
/* 176D0 8003C2D0 8FB00010 */  lw        $s0, 0x10($sp)
/* 176D4 8003C2D4 03E00008 */  jr        $ra
/* 176D8 8003C2D8 27BD0020 */   addiu    $sp, $sp, 0x20
