.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024114C_D599DC
/* D599DC 8024114C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D599E0 80241150 AFBF0010 */  sw        $ra, 0x10($sp)
/* D599E4 80241154 10A00003 */  beqz      $a1, .L80241164
/* D599E8 80241158 8C86000C */   lw       $a2, 0xc($a0)
/* D599EC 8024115C 3C018024 */  lui       $at, %hi(D_80241D98_D5A628)
/* D599F0 80241160 AC201D98 */  sw        $zero, %lo(D_80241D98_D5A628)($at)
.L80241164:
/* D599F4 80241164 3C038024 */  lui       $v1, %hi(D_80241D98_D5A628)
/* D599F8 80241168 24631D98 */  addiu     $v1, $v1, %lo(D_80241D98_D5A628)
/* D599FC 8024116C 8C620000 */  lw        $v0, ($v1)
/* D59A00 80241170 54400003 */  bnel      $v0, $zero, .L80241180
/* D59A04 80241174 AC600000 */   sw       $zero, ($v1)
/* D59A08 80241178 08090465 */  j         .L80241194
/* D59A0C 8024117C 0000102D */   daddu    $v0, $zero, $zero
.L80241180:
/* D59A10 80241180 8CC50000 */  lw        $a1, ($a2)
/* D59A14 80241184 3C068024 */  lui       $a2, %hi(D_80241D9C_D5A62C)
/* D59A18 80241188 0C0B2026 */  jal       evt_set_variable
/* D59A1C 8024118C 8CC61D9C */   lw       $a2, %lo(D_80241D9C_D5A62C)($a2)
/* D59A20 80241190 24020002 */  addiu     $v0, $zero, 2
.L80241194:
/* D59A24 80241194 8FBF0010 */  lw        $ra, 0x10($sp)
/* D59A28 80241198 03E00008 */  jr        $ra
/* D59A2C 8024119C 27BD0018 */   addiu    $sp, $sp, 0x18
