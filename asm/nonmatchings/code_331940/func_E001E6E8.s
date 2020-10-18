.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E001E6E8
/* 332028 E001E6E8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 33202C E001E6EC 0000282D */  daddu     $a1, $zero, $zero
/* 332030 E001E6F0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 332034 E001E6F4 8C83000C */  lw        $v1, 0xc($a0)
/* 332038 E001E6F8 3C02E002 */  lui       $v0, 0xe002
/* 33203C E001E6FC 2442E730 */  addiu     $v0, $v0, -0x18d0
/* 332040 E001E700 AFA40018 */  sw        $a0, 0x18($sp)
/* 332044 E001E704 AFA2001C */  sw        $v0, 0x1c($sp)
/* 332048 E001E708 AFA00014 */  sw        $zero, 0x14($sp)
/* 33204C E001E70C 8C620038 */  lw        $v0, 0x38($v1)
/* 332050 E001E710 10400002 */  beqz      $v0, .LE001E71C
/* 332054 E001E714 27A40010 */   addiu    $a0, $sp, 0x10
/* 332058 E001E718 2405002D */  addiu     $a1, $zero, 0x2d
.LE001E71C:
/* 33205C E001E71C 0C080120 */  jal       func_E0200480
/* 332060 E001E720 AFA50010 */   sw       $a1, 0x10($sp)
/* 332064 E001E724 8FBF0020 */  lw        $ra, 0x20($sp)
/* 332068 E001E728 03E00008 */  jr        $ra
/* 33206C E001E72C 27BD0028 */   addiu    $sp, $sp, 0x28
