.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1494_797454
/* 797454 802A1494 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 797458 802A1498 AFBF0010 */  sw        $ra, 0x10($sp)
/* 79745C 802A149C 8C82000C */  lw        $v0, 0xc($a0)
/* 797460 802A14A0 0C0B1EAF */  jal       get_variable
/* 797464 802A14A4 8C450000 */   lw       $a1, ($v0)
/* 797468 802A14A8 3C058011 */  lui       $a1, %hi(gPlayerData+0x12)
/* 79746C 802A14AC 80A5F2A2 */  lb        $a1, %lo(gPlayerData+0x12)($a1)
/* 797470 802A14B0 24040100 */  addiu     $a0, $zero, 0x100
/* 797474 802A14B4 00051880 */  sll       $v1, $a1, 2
/* 797478 802A14B8 00651821 */  addu      $v1, $v1, $a1
/* 79747C 802A14BC 00621821 */  addu      $v1, $v1, $v0
/* 797480 802A14C0 00031880 */  sll       $v1, $v1, 2
/* 797484 802A14C4 3C06802A */  lui       $a2, %hi(D_8029C890)
/* 797488 802A14C8 00C33021 */  addu      $a2, $a2, $v1
/* 79748C 802A14CC 8CC6C890 */  lw        $a2, %lo(D_8029C890)($a2)
/* 797490 802A14D0 0C098F3F */  jal       set_animation
/* 797494 802A14D4 0000282D */   daddu    $a1, $zero, $zero
/* 797498 802A14D8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 79749C 802A14DC 24020002 */  addiu     $v0, $zero, 2
/* 7974A0 802A14E0 03E00008 */  jr        $ra
/* 7974A4 802A14E4 27BD0018 */   addiu    $sp, $sp, 0x18
