.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417C8_D3BD98
/* D3BD98 802417C8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D3BD9C 802417CC 3C058025 */  lui       $a1, %hi(D_80251468)
/* D3BDA0 802417D0 8CA51468 */  lw        $a1, %lo(D_80251468)($a1)
/* D3BDA4 802417D4 AFBF0010 */  sw        $ra, 0x10($sp)
/* D3BDA8 802417D8 0C0B1EAF */  jal       evt_get_variable
/* D3BDAC 802417DC 0000202D */   daddu    $a0, $zero, $zero
/* D3BDB0 802417E0 0040182D */  daddu     $v1, $v0, $zero
/* D3BDB4 802417E4 24020001 */  addiu     $v0, $zero, 1
/* D3BDB8 802417E8 14620006 */  bne       $v1, $v0, .L80241804
/* D3BDBC 802417EC 24020002 */   addiu    $v0, $zero, 2
/* D3BDC0 802417F0 44800000 */  mtc1      $zero, $f0
/* D3BDC4 802417F4 00000000 */  nop
/* D3BDC8 802417F8 44050000 */  mfc1      $a1, $f0
/* D3BDCC 802417FC 08090607 */  j         .L8024181C
/* D3BDD0 80241800 0000202D */   daddu    $a0, $zero, $zero
.L80241804:
/* D3BDD4 80241804 14620008 */  bne       $v1, $v0, .L80241828
/* D3BDD8 80241808 24040001 */   addiu    $a0, $zero, 1
/* D3BDDC 8024180C 44800000 */  mtc1      $zero, $f0
/* D3BDE0 80241810 00000000 */  nop
/* D3BDE4 80241814 44050000 */  mfc1      $a1, $f0
/* D3BDE8 80241818 00000000 */  nop
.L8024181C:
/* D3BDEC 8024181C 00A0302D */  daddu     $a2, $a1, $zero
/* D3BDF0 80241820 0C01C5A4 */  jal       playFX_50
/* D3BDF4 80241824 00A0382D */   daddu    $a3, $a1, $zero
.L80241828:
/* D3BDF8 80241828 8FBF0010 */  lw        $ra, 0x10($sp)
/* D3BDFC 8024182C 03E00008 */  jr        $ra
/* D3BE00 80241830 27BD0018 */   addiu    $sp, $sp, 0x18
