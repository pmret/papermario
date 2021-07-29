.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005AC44
/* 36044 8005AC44 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 36048 8005AC48 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3604C 8005AC4C 3C01800B */  lui       $at, %hi(D_800B42CC)
/* 36050 8005AC50 A42042CC */  sh        $zero, %lo(D_800B42CC)($at)
/* 36054 8005AC54 3C01800E */  lui       $at, %hi(D_800D91BC)
/* 36058 8005AC58 A42091BC */  sh        $zero, %lo(D_800D91BC)($at)
/* 3605C 8005AC5C 0C00AB4D */  jal       func_8002AD34
/* 36060 8005AC60 00000000 */   nop
/* 36064 8005AC64 8FBF0010 */  lw        $ra, 0x10($sp)
/* 36068 8005AC68 03E00008 */  jr        $ra
/* 3606C 8005AC6C 27BD0018 */   addiu    $sp, $sp, 0x18
