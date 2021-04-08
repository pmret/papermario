.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8023F060
/* 16D940 8023F060 3082FFFF */  andi      $v0, $a0, 0xffff
/* 16D944 8023F064 00A22823 */  subu      $a1, $a1, $v0
/* 16D948 8023F068 00A60018 */  mult      $a1, $a2
/* 16D94C 8023F06C 00001012 */  mflo      $v0
/* 16D950 8023F070 04420001 */  bltzl     $v0, .L8023F078
/* 16D954 8023F074 244200FF */   addiu    $v0, $v0, 0xff
.L8023F078:
/* 16D958 8023F078 00021203 */  sra       $v0, $v0, 8
/* 16D95C 8023F07C 00821021 */  addu      $v0, $a0, $v0
/* 16D960 8023F080 03E00008 */  jr        $ra
/* 16D964 8023F084 3042FFFF */   andi     $v0, $v0, 0xffff
