.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F20_D8A600
/* D8A600 80240F20 3C058016 */  lui       $a1, %hi(gCollisionStatus)
/* D8A604 80240F24 24A5A550 */  addiu     $a1, $a1, %lo(gCollisionStatus)
/* D8A608 80240F28 AC8000AC */  sw        $zero, 0xac($a0)
/* D8A60C 80240F2C 84A20002 */  lh        $v0, 2($a1)
/* D8A610 80240F30 2403001C */  addiu     $v1, $zero, 0x1c
/* D8A614 80240F34 14430002 */  bne       $v0, $v1, .L80240F40
/* D8A618 80240F38 24020001 */   addiu    $v0, $zero, 1
/* D8A61C 80240F3C AC8200AC */  sw        $v0, 0xac($a0)
.L80240F40:
/* D8A620 80240F40 84A20004 */  lh        $v0, 4($a1)
/* D8A624 80240F44 14430002 */  bne       $v0, $v1, .L80240F50
/* D8A628 80240F48 24020001 */   addiu    $v0, $zero, 1
/* D8A62C 80240F4C AC8200AC */  sw        $v0, 0xac($a0)
.L80240F50:
/* D8A630 80240F50 03E00008 */  jr        $ra
/* D8A634 80240F54 24020002 */   addiu    $v0, $zero, 2
