.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80248170
/* 1689D0 80248170 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1689D4 80248174 3C038016 */  lui       $v1, 0x8016
/* 1689D8 80248178 24639D50 */  addiu     $v1, $v1, -0x62b0
/* 1689DC 8024817C 00041140 */  sll       $v0, $a0, 5
/* 1689E0 80248180 00432821 */  addu      $a1, $v0, $v1
/* 1689E4 80248184 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1689E8 80248188 90A3001C */  lbu       $v1, 0x1c($a1)
/* 1689EC 8024818C 24020008 */  addiu     $v0, $zero, 8
/* 1689F0 80248190 14620006 */  bne       $v1, $v0, .L802481AC
/* 1689F4 80248194 00000000 */   nop      
/* 1689F8 80248198 90A20000 */  lbu       $v0, ($a1)
/* 1689FC 8024819C 304200F7 */  andi      $v0, $v0, 0xf7
/* 168A00 802481A0 A0A20000 */  sb        $v0, ($a1)
/* 168A04 802481A4 0C051F9F */  jal       func_80147E7C
/* 168A08 802481A8 24050001 */   addiu    $a1, $zero, 1
.L802481AC:
/* 168A0C 802481AC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 168A10 802481B0 03E00008 */  jr        $ra
/* 168A14 802481B4 27BD0018 */   addiu    $sp, $sp, 0x18
