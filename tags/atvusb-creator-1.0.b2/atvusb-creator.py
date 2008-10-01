#!/usr/bin/python -tt
# coding: utf-8
#
# Copyright © 2008  Red Hat, Inc. All rights reserved.
#
# This copyrighted material is made available to anyone wishing to use, modify,
# copy, or redistribute it subject to the terms and conditions of the GNU
# General Public License v.2.  This program is distributed in the hope that it
# will be useful, but WITHOUT ANY WARRANTY expressed or implied, including the
# implied warranties of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU General Public License for more details.  You should have
# received a copy of the GNU General Public License along with this program; if
# not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth
# Floor, Boston, MA 02110-1301, USA. Any Red Hat trademarks that are
# incorporated in the source code or documentation are not subject to the GNU
# General Public License and may only be used or replicated with the express
# permission of Red Hat, Inc.
#
# Author(s): Luke Macken <lmacken@redhat.com>

__version__ = '0.1.0'

def parse_args():
    from optparse import OptionParser
    parser = OptionParser(version=__version__)
    parser.add_option('-f', '--force', dest='force', action='store',
                      type='string', help='Force the use of a given drive',
                      metavar='DRIVE')
    parser.add_option('-n', '--noverify', dest='noverify', action='store_true',
                      help='Skip checksum verification')
    parser.add_option('-v', '--verbose', dest='verbose', action='store_true',
                      help='Output extra debugging messages')
    return parser.parse_args() # (opts, args)


def main():
    opts, args = parse_args()

    ## Start our graphical interface
    import sys
    from liveusb.gui import LiveUSBApp
    try:
        LiveUSBApp(opts, sys.argv)
    except KeyboardInterrupt:
        pass

if __name__ == '__main__':
    main()
