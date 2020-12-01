.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024114C_D5113C
/* D5113C 8024114C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D51140 80241150 AFBF0010 */  sw        $ra, 0x10($sp)
/* D51144 80241154 10A00003 */  beqz      $a1, .L80241164
/* D51148 80241158 8C86000C */   lw       $a2, 0xc($a0)
/* D5114C 8024115C 3C018024 */  lui       $at, %hi(D_80242ACC)
/* D51150 80241160 AC202ACC */  sw        $zero, %lo(D_80242ACC)($at)
.L80241164:
/* D51154 80241164 3C038024 */  lui       $v1, %hi(D_80242ACC)
/* D51158 80241168 24632ACC */  addiu     $v1, $v1, %lo(D_80242ACC)
/* D5115C 8024116C 8C620000 */  lw        $v0, ($v1)
/* D51160 80241170 54400003 */  bnel      $v0, $zero, .L80241180
/* D51164 80241174 AC600000 */   sw       $zero, ($v1)
/* D51168 80241178 08090465 */  j         .L80241194
/* D5116C 8024117C 0000102D */   daddu    $v0, $zero, $zero
.L80241180:
/* D51170 80241180 8CC50000 */  lw        $a1, ($a2)
/* D51174 80241184 3C068024 */  lui       $a2, %hi(D_80242AD0)
/* D51178 80241188 0C0B2026 */  jal       set_variable
/* D5117C 8024118C 8CC62AD0 */   lw       $a2, %lo(D_80242AD0)($a2)
/* D51180 80241190 24020002 */  addiu     $v0, $zero, 2
.L80241194:
/* D51184 80241194 8FBF0010 */  lw        $ra, 0x10($sp)
/* D51188 80241198 03E00008 */  jr        $ra
/* D5118C 8024119C 27BD0018 */   addiu    $sp, $sp, 0x18
