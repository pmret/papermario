.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel flo_16_UnkFunc44
/* CD2C48 80240E18 AC800084 */  sw        $zero, 0x84($a0)
/* CD2C4C 80240E1C 3C038011 */  lui       $v1, %hi(gPlayerActionState)
/* CD2C50 80240E20 8063F07C */  lb        $v1, %lo(gPlayerActionState)($v1)
/* CD2C54 80240E24 2402000E */  addiu     $v0, $zero, 0xe
/* CD2C58 80240E28 10620004 */  beq       $v1, $v0, .L80240E3C
/* CD2C5C 80240E2C 24020001 */   addiu    $v0, $zero, 1
/* CD2C60 80240E30 24020010 */  addiu     $v0, $zero, 0x10
/* CD2C64 80240E34 14620002 */  bne       $v1, $v0, .L80240E40
/* CD2C68 80240E38 24020001 */   addiu    $v0, $zero, 1
.L80240E3C:
/* CD2C6C 80240E3C AC820084 */  sw        $v0, 0x84($a0)
.L80240E40:
/* CD2C70 80240E40 03E00008 */  jr        $ra
/* CD2C74 80240E44 24020002 */   addiu    $v0, $zero, 2
/* CD2C78 80240E48 00000000 */  nop
/* CD2C7C 80240E4C 00000000 */  nop
