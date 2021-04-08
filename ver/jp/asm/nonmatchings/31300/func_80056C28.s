.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80056C28
/* 32028 80056C28 308400FF */  andi      $a0, $a0, 0xff
/* 3202C 80056C2C 00041140 */  sll       $v0, $a0, 5
/* 32030 80056C30 3C038008 */  lui       $v1, %hi(D_80078E24)
/* 32034 80056C34 8C638E24 */  lw        $v1, %lo(D_80078E24)($v1)
/* 32038 80056C38 00441023 */  subu      $v0, $v0, $a0
/* 3203C 80056C3C 8C63001C */  lw        $v1, 0x1c($v1)
/* 32040 80056C40 00021080 */  sll       $v0, $v0, 2
/* 32044 80056C44 00621821 */  addu      $v1, $v1, $v0
/* 32048 80056C48 24020001 */  addiu     $v0, $zero, 1
/* 3204C 80056C4C 03E00008 */  jr        $ra
/* 32050 80056C50 AC620070 */   sw       $v0, 0x70($v1)
