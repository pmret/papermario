.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240530_8AC4C0
/* 8AC4C0 80240530 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8AC4C4 80240534 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8AC4C8 80240538 8C82000C */  lw        $v0, 0xc($a0)
/* 8AC4CC 8024053C 0C0B1EAF */  jal       get_variable
/* 8AC4D0 80240540 8C450000 */   lw       $a1, ($v0)
/* 8AC4D4 80240544 0C00EABB */  jal       get_npc_unsafe
/* 8AC4D8 80240548 0040202D */   daddu    $a0, $v0, $zero
/* 8AC4DC 8024054C 3C014120 */  lui       $at, 0x4120
/* 8AC4E0 80240550 44810000 */  mtc1      $at, $f0
/* 8AC4E4 80240554 C442003C */  lwc1      $f2, 0x3c($v0)
/* 8AC4E8 80240558 46001080 */  add.s     $f2, $f2, $f0
/* 8AC4EC 8024055C E7A00010 */  swc1      $f0, 0x10($sp)
/* 8AC4F0 80240560 8C450038 */  lw        $a1, 0x38($v0)
/* 8AC4F4 80240564 8C470040 */  lw        $a3, 0x40($v0)
/* 8AC4F8 80240568 44061000 */  mfc1      $a2, $f2
/* 8AC4FC 8024056C 0C01BFBC */  jal       func_8006FEF0
/* 8AC500 80240570 24040003 */   addiu    $a0, $zero, 3
/* 8AC504 80240574 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8AC508 80240578 24020002 */  addiu     $v0, $zero, 2
/* 8AC50C 8024057C 03E00008 */  jr        $ra
/* 8AC510 80240580 27BD0020 */   addiu    $sp, $sp, 0x20
