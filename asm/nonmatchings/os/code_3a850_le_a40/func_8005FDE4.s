.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005FDE4
/* 3B1E4 8005FDE4 8C82000C */  lw        $v0, 0xc($a0)
/* 3B1E8 8005FDE8 90430000 */  lbu       $v1, ($v0)
/* 3B1EC 8005FDEC 00031080 */  sll       $v0, $v1, 2
/* 3B1F0 8005FDF0 00431021 */  addu      $v0, $v0, $v1
/* 3B1F4 8005FDF4 00021040 */  sll       $v0, $v0, 1
/* 3B1F8 8005FDF8 3C01800B */  lui       $at, 0x800b
/* 3B1FC 8005FDFC 00220821 */  addu      $at, $at, $v0
/* 3B200 8005FE00 A4201D42 */  sh        $zero, 0x1d42($at)
/* 3B204 8005FE04 03E00008 */  jr        $ra
/* 3B208 8005FE08 0000102D */   daddu    $v0, $zero, $zero
