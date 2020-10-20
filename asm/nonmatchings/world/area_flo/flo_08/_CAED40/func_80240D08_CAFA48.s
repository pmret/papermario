.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D08_CAFA48
/* CAFA48 80240D08 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* CAFA4C 80240D0C 2463EBB0 */  addiu     $v1, $v1, %lo(D_8010EBB0)
/* CAFA50 80240D10 AC800084 */  sw        $zero, 0x84($a0)
/* CAFA54 80240D14 80620000 */  lb        $v0, ($v1)
/* CAFA58 80240D18 10400005 */  beqz      $v0, .L80240D30
/* CAFA5C 80240D1C 24020003 */   addiu    $v0, $zero, 3
/* CAFA60 80240D20 80630003 */  lb        $v1, 3($v1)
/* CAFA64 80240D24 14620002 */  bne       $v1, $v0, .L80240D30
/* CAFA68 80240D28 24020001 */   addiu    $v0, $zero, 1
/* CAFA6C 80240D2C AC820084 */  sw        $v0, 0x84($a0)
.L80240D30:
/* CAFA70 80240D30 03E00008 */  jr        $ra
/* CAFA74 80240D34 24020002 */   addiu    $v0, $zero, 2
/* CAFA78 80240D38 00000000 */  nop       
/* CAFA7C 80240D3C 00000000 */  nop       
