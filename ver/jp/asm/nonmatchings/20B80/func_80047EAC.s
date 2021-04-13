.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80047EAC
/* 232AC 80047EAC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 232B0 80047EB0 00041040 */  sll       $v0, $a0, 1
/* 232B4 80047EB4 00441021 */  addu      $v0, $v0, $a0
/* 232B8 80047EB8 00021080 */  sll       $v0, $v0, 2
/* 232BC 80047EBC 00441023 */  subu      $v0, $v0, $a0
/* 232C0 80047EC0 3C03800A */  lui       $v1, %hi(D_8009ED54)
/* 232C4 80047EC4 8C63ED54 */  lw        $v1, %lo(D_8009ED54)($v1)
/* 232C8 80047EC8 00021100 */  sll       $v0, $v0, 4
/* 232CC 80047ECC AFBF0010 */  sw        $ra, 0x10($sp)
/* 232D0 80047ED0 00621821 */  addu      $v1, $v1, $v0
/* 232D4 80047ED4 806200A8 */  lb        $v0, 0xa8($v1)
/* 232D8 80047ED8 10400004 */  beqz      $v0, .L80047EEC
/* 232DC 80047EDC 00000000 */   nop
/* 232E0 80047EE0 8C6400AC */  lw        $a0, 0xac($v1)
/* 232E4 80047EE4 0C052669 */  jal       func_801499A4
/* 232E8 80047EE8 A06000A8 */   sb       $zero, 0xa8($v1)
.L80047EEC:
/* 232EC 80047EEC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 232F0 80047EF0 03E00008 */  jr        $ra
/* 232F4 80047EF4 27BD0018 */   addiu    $sp, $sp, 0x18
