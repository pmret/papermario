.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8013A610
/* D0D10 8013A610 0000302D */  daddu     $a2, $zero, $zero
/* D0D14 8013A614 24070004 */  addiu     $a3, $zero, 4
/* D0D18 8013A618 3C038015 */  lui       $v1, %hi(D_80156F20)
/* D0D1C 8013A61C 24636F20 */  addiu     $v1, $v1, %lo(D_80156F20)
.L8013A620:
/* D0D20 8013A620 8C620000 */  lw        $v0, ($v1)
/* D0D24 8013A624 14400005 */  bnez      $v0, .L8013A63C
/* D0D28 8013A628 24C60001 */   addiu    $a2, $a2, 1
/* D0D2C 8013A62C AC640000 */  sw        $a0, ($v1)
/* D0D30 8013A630 A0670004 */  sb        $a3, 4($v1)
/* D0D34 8013A634 03E00008 */  jr        $ra
/* D0D38 8013A638 A0650005 */   sb       $a1, 5($v1)
.L8013A63C:
/* D0D3C 8013A63C 28C20008 */  slti      $v0, $a2, 8
/* D0D40 8013A640 1440FFF7 */  bnez      $v0, .L8013A620
/* D0D44 8013A644 24630008 */   addiu    $v1, $v1, 8
/* D0D48 8013A648 03E00008 */  jr        $ra
/* D0D4C 8013A64C 00000000 */   nop      
