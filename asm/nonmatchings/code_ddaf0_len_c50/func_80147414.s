.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80147414
/* DDB14 80147414 0000302D */  daddu     $a2, $zero, $zero
/* DDB18 80147418 3C058016 */  lui       $a1, %hi(gUIPanels)
/* DDB1C 8014741C 24A59D50 */  addiu     $a1, $a1, %lo(gUIPanels)
/* DDB20 80147420 24A4001C */  addiu     $a0, $a1, 0x1c
.L80147424:
/* DDB24 80147424 90A30000 */  lbu       $v1, ($a1)
/* DDB28 80147428 5060000C */  beql      $v1, $zero, .L8014745C
/* DDB2C 8014742C 24C60001 */   addiu    $a2, $a2, 1
/* DDB30 80147430 30620020 */  andi      $v0, $v1, 0x20
/* DDB34 80147434 14400009 */  bnez      $v0, .L8014745C
/* DDB38 80147438 24C60001 */   addiu    $a2, $a2, 1
/* DDB3C 8014743C 30620002 */  andi      $v0, $v1, 2
/* DDB40 80147440 10400006 */  beqz      $v0, .L8014745C
/* DDB44 80147444 00000000 */   nop      
/* DDB48 80147448 306200FD */  andi      $v0, $v1, 0xfd
/* DDB4C 8014744C A0A20000 */  sb        $v0, ($a1)
/* DDB50 80147450 8C82FFEC */  lw        $v0, -0x14($a0)
/* DDB54 80147454 A0800000 */  sb        $zero, ($a0)
/* DDB58 80147458 AC82FFE8 */  sw        $v0, -0x18($a0)
.L8014745C:
/* DDB5C 8014745C 24840020 */  addiu     $a0, $a0, 0x20
/* DDB60 80147460 28C20040 */  slti      $v0, $a2, 0x40
/* DDB64 80147464 1440FFEF */  bnez      $v0, .L80147424
/* DDB68 80147468 24A50020 */   addiu    $a1, $a1, 0x20
/* DDB6C 8014746C 03E00008 */  jr        $ra
/* DDB70 80147470 00000000 */   nop      
