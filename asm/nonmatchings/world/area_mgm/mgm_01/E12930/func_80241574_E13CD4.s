.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241574_E13CD4
/* E13CD4 80241574 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E13CD8 80241578 AFBF0010 */  sw        $ra, 0x10($sp)
/* E13CDC 8024157C 0C00FB3A */  jal       get_enemy
/* E13CE0 80241580 0000202D */   daddu    $a0, $zero, $zero
/* E13CE4 80241584 0000302D */  daddu     $a2, $zero, $zero
/* E13CE8 80241588 2407FFFF */  addiu     $a3, $zero, -1
/* E13CEC 8024158C 3C058024 */  lui       $a1, %hi(D_80241B70)
/* E13CF0 80241590 24A51B70 */  addiu     $a1, $a1, %lo(D_80241B70)
/* E13CF4 80241594 8C420080 */  lw        $v0, 0x80($v0)
/* E13CF8 80241598 3C048024 */  lui       $a0, %hi(D_80241B44)
/* E13CFC 8024159C 24841B44 */  addiu     $a0, $a0, %lo(D_80241B44)
/* E13D00 802415A0 0040182D */  daddu     $v1, $v0, $zero
/* E13D04 802415A4 AC60000C */  sw        $zero, 0xc($v1)
/* E13D08 802415A8 AC600010 */  sw        $zero, 0x10($v1)
.L802415AC:
/* E13D0C 802415AC AC600074 */  sw        $zero, 0x74($v1)
/* E13D10 802415B0 8C820000 */  lw        $v0, ($a0)
/* E13D14 802415B4 24840004 */  addiu     $a0, $a0, 4
/* E13D18 802415B8 24C60001 */  addiu     $a2, $a2, 1
/* E13D1C 802415BC AC620078 */  sw        $v0, 0x78($v1)
/* E13D20 802415C0 8CA20000 */  lw        $v0, ($a1)
/* E13D24 802415C4 24A50004 */  addiu     $a1, $a1, 4
/* E13D28 802415C8 AC670084 */  sw        $a3, 0x84($v1)
/* E13D2C 802415CC AC62007C */  sw        $v0, 0x7c($v1)
/* E13D30 802415D0 28C2000B */  slti      $v0, $a2, 0xb
/* E13D34 802415D4 1440FFF5 */  bnez      $v0, .L802415AC
/* E13D38 802415D8 2463005C */   addiu    $v1, $v1, 0x5c
/* E13D3C 802415DC 8FBF0010 */  lw        $ra, 0x10($sp)
/* E13D40 802415E0 24020002 */  addiu     $v0, $zero, 2
/* E13D44 802415E4 03E00008 */  jr        $ra
/* E13D48 802415E8 27BD0018 */   addiu    $sp, $sp, 0x18
