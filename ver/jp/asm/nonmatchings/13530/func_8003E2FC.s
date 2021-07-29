.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003E2FC
/* 196FC 8003E2FC 3C03800A */  lui       $v1, %hi(D_8009A5E0)
/* 19700 8003E300 8C63A5E0 */  lw        $v1, %lo(D_8009A5E0)($v1)
/* 19704 8003E304 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 19708 8003E308 10600006 */  beqz      $v1, .L8003E324
/* 1970C 8003E30C AFBF0010 */   sw       $ra, 0x10($sp)
/* 19710 8003E310 24020003 */  addiu     $v0, $zero, 3
/* 19714 8003E314 14620003 */  bne       $v1, $v0, .L8003E324
/* 19718 8003E318 00000000 */   nop
/* 1971C 8003E31C 0C010647 */  jal       func_8004191C
/* 19720 8003E320 00000000 */   nop
.L8003E324:
/* 19724 8003E324 8FBF0010 */  lw        $ra, 0x10($sp)
/* 19728 8003E328 03E00008 */  jr        $ra
/* 1972C 8003E32C 27BD0018 */   addiu    $sp, $sp, 0x18
