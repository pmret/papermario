.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel contRmbStartMesg
/* 3B158 8005FD58 8C84000C */  lw        $a0, 0xc($a0)
/* 3B15C 8005FD5C 90830000 */  lbu       $v1, ($a0)
/* 3B160 8005FD60 8C850008 */  lw        $a1, 8($a0)
/* 3B164 8005FD64 00031080 */  sll       $v0, $v1, 2
/* 3B168 8005FD68 00431021 */  addu      $v0, $v0, $v1
/* 3B16C 8005FD6C 90A30006 */  lbu       $v1, 6($a1)
/* 3B170 8005FD70 00021040 */  sll       $v0, $v0, 1
/* 3B174 8005FD74 3C01800B */  lui       $at, 0x800b
/* 3B178 8005FD78 00220821 */  addu      $at, $at, $v0
/* 3B17C 8005FD7C A0231D46 */  sb        $v1, 0x1d46($at)
/* 3B180 8005FD80 90830000 */  lbu       $v1, ($a0)
/* 3B184 8005FD84 00031080 */  sll       $v0, $v1, 2
/* 3B188 8005FD88 00431021 */  addu      $v0, $v0, $v1
/* 3B18C 8005FD8C 94A30002 */  lhu       $v1, 2($a1)
/* 3B190 8005FD90 00021040 */  sll       $v0, $v0, 1
/* 3B194 8005FD94 3C01800B */  lui       $at, 0x800b
/* 3B198 8005FD98 00220821 */  addu      $at, $at, $v0
/* 3B19C 8005FD9C A4231D42 */  sh        $v1, 0x1d42($at)
/* 3B1A0 8005FDA0 90830000 */  lbu       $v1, ($a0)
/* 3B1A4 8005FDA4 00031080 */  sll       $v0, $v1, 2
/* 3B1A8 8005FDA8 00431021 */  addu      $v0, $v0, $v1
/* 3B1AC 8005FDAC 94A30000 */  lhu       $v1, ($a1)
/* 3B1B0 8005FDB0 00021040 */  sll       $v0, $v0, 1
/* 3B1B4 8005FDB4 3C01800B */  lui       $at, 0x800b
/* 3B1B8 8005FDB8 00220821 */  addu      $at, $at, $v0
/* 3B1BC 8005FDBC A4231D40 */  sh        $v1, 0x1d40($at)
/* 3B1C0 8005FDC0 90830000 */  lbu       $v1, ($a0)
/* 3B1C4 8005FDC4 00031080 */  sll       $v0, $v1, 2
/* 3B1C8 8005FDC8 00431021 */  addu      $v0, $v0, $v1
/* 3B1CC 8005FDCC 00021040 */  sll       $v0, $v0, 1
/* 3B1D0 8005FDD0 3C01800B */  lui       $at, 0x800b
/* 3B1D4 8005FDD4 00220821 */  addu      $at, $at, $v0
/* 3B1D8 8005FDD8 A4201D44 */  sh        $zero, 0x1d44($at)
/* 3B1DC 8005FDDC 03E00008 */  jr        $ra
/* 3B1E0 8005FDE0 0000102D */   daddu    $v0, $zero, $zero
