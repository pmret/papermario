.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80047A00
/* 22E00 80047A00 00041040 */  sll       $v0, $a0, 1
/* 22E04 80047A04 00441021 */  addu      $v0, $v0, $a0
/* 22E08 80047A08 00021080 */  sll       $v0, $v0, 2
/* 22E0C 80047A0C 00441023 */  subu      $v0, $v0, $a0
/* 22E10 80047A10 3C03800A */  lui       $v1, %hi(D_800A0F44)
/* 22E14 80047A14 8C630F44 */  lw        $v1, %lo(D_800A0F44)($v1)
/* 22E18 80047A18 00021100 */  sll       $v0, $v0, 4
/* 22E1C 80047A1C 00621821 */  addu      $v1, $v1, $v0
/* 22E20 80047A20 8C620000 */  lw        $v0, ($v1)
/* 22E24 80047A24 34420008 */  ori       $v0, $v0, 8
/* 22E28 80047A28 03E00008 */  jr        $ra
/* 22E2C 80047A2C AC620000 */   sw       $v0, ($v1)
