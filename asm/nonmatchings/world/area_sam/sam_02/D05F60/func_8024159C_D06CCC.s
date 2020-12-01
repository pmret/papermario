.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024159C_D06CCC
/* D06CCC 8024159C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D06CD0 802415A0 AFBF0010 */  sw        $ra, 0x10($sp)
/* D06CD4 802415A4 8C82000C */  lw        $v0, 0xc($a0)
/* D06CD8 802415A8 0C0B1EAF */  jal       get_variable
/* D06CDC 802415AC 8C450000 */   lw       $a1, ($v0)
/* D06CE0 802415B0 0040202D */  daddu     $a0, $v0, $zero
/* D06CE4 802415B4 3C028025 */  lui       $v0, %hi(D_8024B9B0)
/* D06CE8 802415B8 8C42B9B0 */  lw        $v0, %lo(D_8024B9B0)($v0)
/* D06CEC 802415BC 24030001 */  addiu     $v1, $zero, 1
/* D06CF0 802415C0 8C45000C */  lw        $a1, 0xc($v0)
/* D06CF4 802415C4 1083000D */  beq       $a0, $v1, .L802415FC
/* D06CF8 802415C8 28820002 */   slti     $v0, $a0, 2
/* D06CFC 802415CC 10400005 */  beqz      $v0, .L802415E4
/* D06D00 802415D0 24020002 */   addiu    $v0, $zero, 2
/* D06D04 802415D4 10800007 */  beqz      $a0, .L802415F4
/* D06D08 802415D8 240200C0 */   addiu    $v0, $zero, 0xc0
/* D06D0C 802415DC 08090583 */  j         .L8024160C
/* D06D10 802415E0 ACA00038 */   sw       $zero, 0x38($a1)
.L802415E4:
/* D06D14 802415E4 10820008 */  beq       $a0, $v0, .L80241608
/* D06D18 802415E8 24020040 */   addiu    $v0, $zero, 0x40
/* D06D1C 802415EC 08090583 */  j         .L8024160C
/* D06D20 802415F0 ACA00038 */   sw       $zero, 0x38($a1)
.L802415F4:
/* D06D24 802415F4 08090583 */  j         .L8024160C
/* D06D28 802415F8 ACA20038 */   sw       $v0, 0x38($a1)
.L802415FC:
/* D06D2C 802415FC 24020080 */  addiu     $v0, $zero, 0x80
/* D06D30 80241600 08090583 */  j         .L8024160C
/* D06D34 80241604 ACA20038 */   sw       $v0, 0x38($a1)
.L80241608:
/* D06D38 80241608 ACA20038 */  sw        $v0, 0x38($a1)
.L8024160C:
/* D06D3C 8024160C 8FBF0010 */  lw        $ra, 0x10($sp)
/* D06D40 80241610 24020002 */  addiu     $v0, $zero, 2
/* D06D44 80241614 03E00008 */  jr        $ra
/* D06D48 80241618 27BD0018 */   addiu    $sp, $sp, 0x18
