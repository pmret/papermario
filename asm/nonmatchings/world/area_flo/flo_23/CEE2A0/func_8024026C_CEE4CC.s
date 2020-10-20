.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024026C_CEE4CC
/* CEE4CC 8024026C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CEE4D0 80240270 AFBF0010 */  sw        $ra, 0x10($sp)
/* CEE4D4 80240274 10A00003 */  beqz      $a1, .L80240284
/* CEE4D8 80240278 8C86000C */   lw       $a2, 0xc($a0)
/* CEE4DC 8024027C 3C018024 */  lui       $at, 0x8024
/* CEE4E0 80240280 AC20130C */  sw        $zero, 0x130c($at)
.L80240284:
/* CEE4E4 80240284 3C038024 */  lui       $v1, 0x8024
/* CEE4E8 80240288 2463130C */  addiu     $v1, $v1, 0x130c
/* CEE4EC 8024028C 8C620000 */  lw        $v0, ($v1)
/* CEE4F0 80240290 54400003 */  bnel      $v0, $zero, .L802402A0
/* CEE4F4 80240294 AC600000 */   sw       $zero, ($v1)
/* CEE4F8 80240298 080900AD */  j         .L802402B4
/* CEE4FC 8024029C 0000102D */   daddu    $v0, $zero, $zero
.L802402A0:
/* CEE500 802402A0 8CC50000 */  lw        $a1, ($a2)
/* CEE504 802402A4 3C068024 */  lui       $a2, 0x8024
/* CEE508 802402A8 0C0B2026 */  jal       set_variable
/* CEE50C 802402AC 8CC61310 */   lw       $a2, 0x1310($a2)
/* CEE510 802402B0 24020002 */  addiu     $v0, $zero, 2
.L802402B4:
/* CEE514 802402B4 8FBF0010 */  lw        $ra, 0x10($sp)
/* CEE518 802402B8 03E00008 */  jr        $ra
/* CEE51C 802402BC 27BD0018 */   addiu    $sp, $sp, 0x18
