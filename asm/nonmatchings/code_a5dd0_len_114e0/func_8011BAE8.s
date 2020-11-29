.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011BAE8
/* B21E8 8011BAE8 0000202D */  daddu     $a0, $zero, $zero
/* B21EC 8011BAEC 3C058015 */  lui       $a1, %hi(gCurrentModelListPtr)
/* B21F0 8011BAF0 8CA512CC */  lw        $a1, %lo(gCurrentModelListPtr)($a1)
.L8011BAF4:
/* B21F4 8011BAF4 8CA30000 */  lw        $v1, ($a1)
/* B21F8 8011BAF8 10600004 */  beqz      $v1, .L8011BB0C
/* B21FC 8011BAFC 24840001 */   addiu    $a0, $a0, 1
/* B2200 8011BB00 94620000 */  lhu       $v0, ($v1)
/* B2204 8011BB04 3042FBFF */  andi      $v0, $v0, 0xfbff
/* B2208 8011BB08 A4620000 */  sh        $v0, ($v1)
.L8011BB0C:
/* B220C 8011BB0C 28820100 */  slti      $v0, $a0, 0x100
/* B2210 8011BB10 1440FFF8 */  bnez      $v0, .L8011BAF4
/* B2214 8011BB14 24A50004 */   addiu    $a1, $a1, 4
/* B2218 8011BB18 0000202D */  daddu     $a0, $zero, $zero
/* B221C 8011BB1C 3C058015 */  lui       $a1, %hi(D_801512E0)
/* B2220 8011BB20 8CA512E0 */  lw        $a1, %lo(D_801512E0)($a1)
.L8011BB24:
/* B2224 8011BB24 8CA30000 */  lw        $v1, ($a1)
/* B2228 8011BB28 10600004 */  beqz      $v1, .L8011BB3C
/* B222C 8011BB2C 24840001 */   addiu    $a0, $a0, 1
/* B2230 8011BB30 94620000 */  lhu       $v0, ($v1)
/* B2234 8011BB34 3042FBFF */  andi      $v0, $v0, 0xfbff
/* B2238 8011BB38 A4620000 */  sh        $v0, ($v1)
.L8011BB3C:
/* B223C 8011BB3C 28820004 */  slti      $v0, $a0, 4
/* B2240 8011BB40 1440FFF8 */  bnez      $v0, .L8011BB24
/* B2244 8011BB44 24A50004 */   addiu    $a1, $a1, 4
/* B2248 8011BB48 03E00008 */  jr        $ra
/* B224C 8011BB4C 00000000 */   nop      
