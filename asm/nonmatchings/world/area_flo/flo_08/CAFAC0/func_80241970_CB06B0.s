.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241970_CB06B0
/* CB06B0 80241970 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CB06B4 80241974 AFBF0010 */  sw        $ra, 0x10($sp)
/* CB06B8 80241978 10A00003 */  beqz      $a1, .L80241988
/* CB06BC 8024197C 8C86000C */   lw       $a2, 0xc($a0)
/* CB06C0 80241980 3C018024 */  lui       $at, %hi(D_80243088)
/* CB06C4 80241984 AC203088 */  sw        $zero, %lo(D_80243088)($at)
.L80241988:
/* CB06C8 80241988 3C038024 */  lui       $v1, %hi(D_80243088)
/* CB06CC 8024198C 24633088 */  addiu     $v1, $v1, %lo(D_80243088)
/* CB06D0 80241990 8C620000 */  lw        $v0, ($v1)
/* CB06D4 80241994 54400003 */  bnel      $v0, $zero, .L802419A4
/* CB06D8 80241998 AC600000 */   sw       $zero, ($v1)
/* CB06DC 8024199C 0809066E */  j         .L802419B8
/* CB06E0 802419A0 0000102D */   daddu    $v0, $zero, $zero
.L802419A4:
/* CB06E4 802419A4 8CC50000 */  lw        $a1, ($a2)
/* CB06E8 802419A8 3C068024 */  lui       $a2, %hi(D_8024308C)
/* CB06EC 802419AC 0C0B2026 */  jal       set_variable
/* CB06F0 802419B0 8CC6308C */   lw       $a2, %lo(D_8024308C)($a2)
/* CB06F4 802419B4 24020002 */  addiu     $v0, $zero, 2
.L802419B8:
/* CB06F8 802419B8 8FBF0010 */  lw        $ra, 0x10($sp)
/* CB06FC 802419BC 03E00008 */  jr        $ra
/* CB0700 802419C0 27BD0018 */   addiu    $sp, $sp, 0x18
