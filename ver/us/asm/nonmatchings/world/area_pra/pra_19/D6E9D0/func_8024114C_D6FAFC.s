.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024114C_D6FAFC
/* D6FAFC 8024114C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D6FB00 80241150 AFBF0010 */  sw        $ra, 0x10($sp)
/* D6FB04 80241154 10A00003 */  beqz      $a1, .L80241164
/* D6FB08 80241158 8C86000C */   lw       $a2, 0xc($a0)
/* D6FB0C 8024115C 3C018024 */  lui       $at, %hi(D_8024219C_D70B4C)
/* D6FB10 80241160 AC20219C */  sw        $zero, %lo(D_8024219C_D70B4C)($at)
.L80241164:
/* D6FB14 80241164 3C038024 */  lui       $v1, %hi(D_8024219C_D70B4C)
/* D6FB18 80241168 2463219C */  addiu     $v1, $v1, %lo(D_8024219C_D70B4C)
/* D6FB1C 8024116C 8C620000 */  lw        $v0, ($v1)
/* D6FB20 80241170 54400003 */  bnel      $v0, $zero, .L80241180
/* D6FB24 80241174 AC600000 */   sw       $zero, ($v1)
/* D6FB28 80241178 08090465 */  j         .L80241194
/* D6FB2C 8024117C 0000102D */   daddu    $v0, $zero, $zero
.L80241180:
/* D6FB30 80241180 8CC50000 */  lw        $a1, ($a2)
/* D6FB34 80241184 3C068024 */  lui       $a2, %hi(D_802421A0_D70B50)
/* D6FB38 80241188 0C0B2026 */  jal       set_variable
/* D6FB3C 8024118C 8CC621A0 */   lw       $a2, %lo(D_802421A0_D70B50)($a2)
/* D6FB40 80241190 24020002 */  addiu     $v0, $zero, 2
.L80241194:
/* D6FB44 80241194 8FBF0010 */  lw        $ra, 0x10($sp)
/* D6FB48 80241198 03E00008 */  jr        $ra
/* D6FB4C 8024119C 27BD0018 */   addiu    $sp, $sp, 0x18
