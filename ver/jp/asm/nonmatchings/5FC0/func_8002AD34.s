.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002AD34
/* 6134 8002AD34 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6138 8002AD38 AFBF0010 */  sw        $ra, 0x10($sp)
/* 613C 8002AD3C 3C050001 */  lui       $a1, 1
/* 6140 8002AD40 3C048027 */  lui       $a0, %hi(D_80268000)
/* 6144 8002AD44 24848000 */  addiu     $a0, $a0, %lo(D_80268000)
/* 6148 8002AD48 0C00A3FC */  jal       func_80028FF0
/* 614C 8002AD4C 34A58000 */   ori      $a1, $a1, 0x8000
/* 6150 8002AD50 0040202D */  daddu     $a0, $v0, $zero
/* 6154 8002AD54 2402FFFF */  addiu     $v0, $zero, -1
/* 6158 8002AD58 0040182D */  daddu     $v1, $v0, $zero
/* 615C 8002AD5C 54830001 */  bnel      $a0, $v1, .L8002AD64
/* 6160 8002AD60 0000102D */   daddu    $v0, $zero, $zero
.L8002AD64:
/* 6164 8002AD64 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6168 8002AD68 03E00008 */  jr        $ra
/* 616C 8002AD6C 27BD0018 */   addiu    $sp, $sp, 0x18
