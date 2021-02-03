.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024199C_ECB69C
/* ECB69C 8024199C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ECB6A0 802419A0 AFBF0010 */  sw        $ra, 0x10($sp)
/* ECB6A4 802419A4 10A00003 */  beqz      $a1, .L802419B4
/* ECB6A8 802419A8 8C86000C */   lw       $a2, 0xc($a0)
/* ECB6AC 802419AC 3C018024 */  lui       $at, %hi(D_802430B8_ECCDB8)
/* ECB6B0 802419B0 AC2030B8 */  sw        $zero, %lo(D_802430B8_ECCDB8)($at)
.L802419B4:
/* ECB6B4 802419B4 3C038024 */  lui       $v1, %hi(D_802430B8_ECCDB8)
/* ECB6B8 802419B8 246330B8 */  addiu     $v1, $v1, %lo(D_802430B8_ECCDB8)
/* ECB6BC 802419BC 8C620000 */  lw        $v0, ($v1)
/* ECB6C0 802419C0 54400003 */  bnel      $v0, $zero, .L802419D0
/* ECB6C4 802419C4 AC600000 */   sw       $zero, ($v1)
/* ECB6C8 802419C8 08090679 */  j         .L802419E4
/* ECB6CC 802419CC 0000102D */   daddu    $v0, $zero, $zero
.L802419D0:
/* ECB6D0 802419D0 8CC50000 */  lw        $a1, ($a2)
/* ECB6D4 802419D4 3C068024 */  lui       $a2, %hi(D_802430BC_ECCDBC)
/* ECB6D8 802419D8 0C0B551A */  jal       func_802D5468
/* ECB6DC 802419DC 8CC630BC */   lw       $a2, %lo(D_802430BC_ECCDBC)($a2)
/* ECB6E0 802419E0 24020002 */  addiu     $v0, $zero, 2
.L802419E4:
/* ECB6E4 802419E4 8FBF0010 */  lw        $ra, 0x10($sp)
/* ECB6E8 802419E8 03E00008 */  jr        $ra
/* ECB6EC 802419EC 27BD0018 */   addiu    $sp, $sp, 0x18
