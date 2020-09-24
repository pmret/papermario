.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002E7CC
/* 9BCC 8002E7CC 3C08800B */  lui       $t0, 0x800b
/* 9BD0 8002E7D0 25081D80 */  addiu     $t0, $t0, 0x1d80
/* 9BD4 8002E7D4 00041080 */  sll       $v0, $a0, 2
/* 9BD8 8002E7D8 00441021 */  addu      $v0, $v0, $a0
/* 9BDC 8002E7DC 00021080 */  sll       $v0, $v0, 2
/* 9BE0 8002E7E0 00441023 */  subu      $v0, $v0, $a0
/* 9BE4 8002E7E4 000218C0 */  sll       $v1, $v0, 3
/* 9BE8 8002E7E8 00431021 */  addu      $v0, $v0, $v1
/* 9BEC 8002E7EC 000210C0 */  sll       $v0, $v0, 3
/* 9BF0 8002E7F0 00481021 */  addu      $v0, $v0, $t0
/* 9BF4 8002E7F4 8443000E */  lh        $v1, 0xe($v0)
/* 9BF8 8002E7F8 8FA80010 */  lw        $t0, 0x10($sp)
/* 9BFC 8002E7FC ACA30000 */  sw        $v1, ($a1)
/* 9C00 8002E800 84430010 */  lh        $v1, 0x10($v0)
/* 9C04 8002E804 ACC30000 */  sw        $v1, ($a2)
/* 9C08 8002E808 8443000E */  lh        $v1, 0xe($v0)
/* 9C0C 8002E80C 8444000A */  lh        $a0, 0xa($v0)
/* 9C10 8002E810 00641821 */  addu      $v1, $v1, $a0
/* 9C14 8002E814 ACE30000 */  sw        $v1, ($a3)
/* 9C18 8002E818 84430010 */  lh        $v1, 0x10($v0)
/* 9C1C 8002E81C 8442000C */  lh        $v0, 0xc($v0)
/* 9C20 8002E820 00621821 */  addu      $v1, $v1, $v0
/* 9C24 8002E824 03E00008 */  jr        $ra
/* 9C28 8002E828 AD030000 */   sw       $v1, ($t0)
