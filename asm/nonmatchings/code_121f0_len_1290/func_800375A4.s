.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800375A4
/* 129A4 800375A4 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 129A8 800375A8 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 129AC 800375AC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 129B0 800375B0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 129B4 800375B4 804300AC */  lb        $v1, 0xac($v0)
/* 129B8 800375B8 2C620006 */  sltiu     $v0, $v1, 6
/* 129BC 800375BC 1040001B */  beqz      $v0, .L8003762C
/* 129C0 800375C0 00031080 */   sll      $v0, $v1, 2
/* 129C4 800375C4 3C01800A */  lui       $at, %hi(D_800983C8)
/* 129C8 800375C8 00220821 */  addu      $at, $at, $v0
/* 129CC 800375CC 8C2283C8 */  lw        $v0, %lo(D_800983C8)($at)
/* 129D0 800375D0 00400008 */  jr        $v0
/* 129D4 800375D4 00000000 */   nop      
/* 129D8 800375D8 3C018007 */  lui       $at, %hi(D_80077A28)
/* 129DC 800375DC AC207A28 */  sw        $zero, %lo(D_80077A28)($at)
/* 129E0 800375E0 3C018007 */  lui       $at, %hi(D_80077A2C)
/* 129E4 800375E4 AC207A2C */  sw        $zero, %lo(D_80077A2C)($at)
/* 129E8 800375E8 3C018007 */  lui       $at, %hi(D_80077A30)
/* 129EC 800375EC 0800DD89 */  j         .L80037624
/* 129F0 800375F0 AC207A30 */   sw       $zero, %lo(D_80077A30)($at)
/* 129F4 800375F4 0C00DE58 */  jal       func_80037960
/* 129F8 800375F8 00000000 */   nop      
/* 129FC 800375FC 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 12A00 80037600 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 12A04 80037604 90420073 */  lbu       $v0, 0x73($v0)
/* 12A08 80037608 30420001 */  andi      $v0, $v0, 1
/* 12A0C 8003760C 10400007 */  beqz      $v0, .L8003762C
/* 12A10 80037610 00000000 */   nop      
/* 12A14 80037614 0C00DEF2 */  jal       func_80037BC8
/* 12A18 80037618 00000000 */   nop      
/* 12A1C 8003761C 0800DD8B */  j         .L8003762C
/* 12A20 80037620 00000000 */   nop      
.L80037624:
/* 12A24 80037624 0C00DE58 */  jal       func_80037960
/* 12A28 80037628 00000000 */   nop      
.L8003762C:
/* 12A2C 8003762C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 12A30 80037630 03E00008 */  jr        $ra
/* 12A34 80037634 27BD0018 */   addiu    $sp, $sp, 0x18
