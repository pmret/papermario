.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238E74_6F1F54
/* 6F1F54 80238E74 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 6F1F58 80238E78 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 6F1F5C 80238E7C 8C4500DC */  lw        $a1, 0xdc($v0)
/* 6F1F60 80238E80 AC800084 */  sw        $zero, 0x84($a0)
/* 6F1F64 80238E84 8443017C */  lh        $v1, 0x17c($v0)
/* 6F1F68 80238E88 24020087 */  addiu     $v0, $zero, 0x87
/* 6F1F6C 80238E8C 1062000A */  beq       $v1, $v0, .L80238EB8
/* 6F1F70 80238E90 28620088 */   slti     $v0, $v1, 0x88
/* 6F1F74 80238E94 10400005 */  beqz      $v0, .L80238EAC
/* 6F1F78 80238E98 24020086 */   addiu    $v0, $zero, 0x86
/* 6F1F7C 80238E9C 10620006 */  beq       $v1, $v0, .L80238EB8
/* 6F1F80 80238EA0 24020002 */   addiu    $v0, $zero, 2
/* 6F1F84 80238EA4 0808E3B5 */  j         .L80238ED4
/* 6F1F88 80238EA8 00000000 */   nop      
.L80238EAC:
/* 6F1F8C 80238EAC 24020088 */  addiu     $v0, $zero, 0x88
/* 6F1F90 80238EB0 14620008 */  bne       $v1, $v0, .L80238ED4
/* 6F1F94 80238EB4 24020002 */   addiu    $v0, $zero, 2
.L80238EB8:
/* 6F1F98 80238EB8 80A20220 */  lb        $v0, 0x220($a1)
/* 6F1F9C 80238EBC 28420063 */  slti      $v0, $v0, 0x63
/* 6F1FA0 80238EC0 14400004 */  bnez      $v0, .L80238ED4
/* 6F1FA4 80238EC4 24020002 */   addiu    $v0, $zero, 2
/* 6F1FA8 80238EC8 24020001 */  addiu     $v0, $zero, 1
/* 6F1FAC 80238ECC AC820084 */  sw        $v0, 0x84($a0)
/* 6F1FB0 80238ED0 24020002 */  addiu     $v0, $zero, 2
.L80238ED4:
/* 6F1FB4 80238ED4 03E00008 */  jr        $ra
/* 6F1FB8 80238ED8 00000000 */   nop      
